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
		LL n, x;
		string s;
		cin >> n >> x;
		cin >> s;
		vector<LL> count0(n + 1, 0), count1(n + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == '0')
			{
				count0[i] = count0[i - 1] + 1;
				count1[i] = count1[i - 1];
			}
			else
			{
				count0[i] = count0[i - 1];
				count1[i] = count1[i - 1] + 1;
			}
		}

		LL k = count0[n] - count1[n];
		int res = 0;

		for (int i = 0; i < n; i++)
		{
			LL d = x - (count0[i] - count1[i]);

			if (d == 0)
			{
				res++;
				continue;
			}

			if (d != 0 && k != 0)
			{
				if (d * k > 0)
					if (d % k == 0)
						res++;
			}

		}

		if (k == 0 && res != 0)
			cout << -1 << endl;
		else
			cout << res << endl;

	}



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1295/problem/B
 */
