#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n,0), b(n,0), c(n,0), res(n,0);

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			ti--;

			a[i] = ti;
			b[ti] = i;
		}

		c[0] = 1;
		res[0] = res[n - 1] = 1;

		int i = 1, l = b[0], r = b[0], pos = 1;
		
		while (true)
		{
			if (pos == n)
				break;

			int d = b[i];

			if (d < l)
			{
				for (int j = d; j < l; j++)
					c[a[j]] = 1;
				l = d;
			}
			else
			{
				for (int j = r + 1; j <= d; j++)
					c[a[j]] = 1;
				r = d;
			}

			while (pos<n &&c[pos])
				pos++;

			i = pos;

			if (pos == r - l + 1)
				res[pos - 1] = 1;

		}

		for (int i = 0; i < n; i++)
			cout << res[i];

		cout << endl;

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1265/problem/B
 */
