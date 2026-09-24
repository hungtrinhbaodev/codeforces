#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long int
#define module 998244353
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<pair<int, int>>> dp;
	vector<int> a;
	int n, h, l, r;

	cin >> n >> h >> l >> r;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
	}


	for (int i = 0; i <= n; i++)
	{
		vector<pair<int, int>> tv;
		dp.push_back(tv);

		for (int j = 0; j < h; j++)
		{
			dp[i].push_back(make_pair(0, 0));
		}
	}

	dp[0][0] = make_pair(1, 0);

	for (int i = 0; i < n; i++)
	{
		int a1, a2;
		a1 = a[i];
		a2 = a[i] - 1;


		for (int j = 0; j < h; j++)
		{
			int t1 = j - a1, t2 = j - a2;
			if (t1 < 0)
				t1 += h;

			if (t2 < 0)
				t2 += h;

			pair<int, int> dp1, dp2;
			
			dp1 = dp[i][t1];
			dp2 = dp[i][t2];

			if (dp1.first == 0)
			{
				if (dp2.first != 0)
				{
					if (j <= r && j >= l)
					{
						dp2.second += 1;	
					}
					dp[i + 1][j] = dp2;
				}
			}
			else
			{
				if (dp2.first == 0)
				{
					if (dp1.first != 0)
					{
						if (j <= r && j >= l)
						{
							dp1.second += 1;
						}
						dp[i + 1][j] = dp1;
					}
				}
				else
				{
					if (dp1.second < dp2.second)
						swap(dp1, dp2);

					if (j <= r && j >= l)
					{
						dp1.second += 1;
					}
					dp[i + 1][j] = dp1;
				}
			}

		}
	}

	int res = -1;
	for (int i = 0; i < h; i++)
	{
		if (dp[n][i].second > res)
			res = dp[n][i].second;
	}

	cout << res << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1324/problem/E
 */
