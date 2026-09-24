#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<map>
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
		vector<int> a, dp;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			dp.push_back(0);
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		dp[0] = 1;

		for (int i = 1; i < n; i++)
		{
			int index = i + 1;
			int max = 1;
			for (int j = 1; j <= sqrt(index); j++)
			{
				if (index % j == 0)
				{
					int k = index / j;

					if (a[i] > a[j - 1] && dp[j - 1] + 1 > max)
					{
						max = dp[j - 1] + 1;
					}

					if (a[i] > a[k - 1] && dp[k - 1] + 1 > max )
					{
						max = dp[k - 1] + 1;
					}
				}	
			}
			dp[i] = max;
		}

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (dp[i] > res)
				res = dp[i];
		}

		cout << res << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1350/problem/B
 */
