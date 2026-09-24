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
		vector<int> a, b, c(3,0);
		
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);

			c[ti + 1]++;

		}

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			b.push_back(ti);
		}

		if (a[0] != b[0])
			cout << "NO" << endl;
		else
		{
			bool ac = true;

			for (int i = n - 1; i > 0 && ac; i--)
			{
				c[a[i] + 1]--;

				if (b[i] - a[i] > 0)
				{
					if (c[2] <= 0)
						ac = false;
				}
				else if (b[i] - a[i] < 0)
				{
					if (c[0] <= 0)
						ac = false;
				}
			}

			if (ac)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1333/problem/B
 */
