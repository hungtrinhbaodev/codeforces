#include<iostream>
#include<vector>
#include<algorithm>
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
		LL INF = (LL)(10e17);
		LL n, a, b;
		cin >> n >> a >> b;



		string s;
		cin >> s;


		vector<vector<LL>> dp(2);
		vector<bool> ban;
		for (int i = 0; i < n + 1; i++)
		{
			dp[0].push_back(0);
			dp[1].push_back(0);
			ban.push_back(false);
		}

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				ban[i] = ban[i + 1] = true;
			}
		}

		for (int i = 0; i <= n; i++)
		{
			if (i == 0)
			{
				if (ban[i])
				{
					dp[0][0] = INF;
				}
				else
					dp[0][0] = b;

				dp[1][0] = INF;
			}
			else
			{
				if (dp[0][i - 1] + 2 * a + 2 * b < dp[1][i - 1] + a + 2 * b)
					dp[1][i] = dp[0][i - 1] + 2 * a + 2 * b;
				else
					dp[1][i] = dp[1][i - 1] + a + 2 * b;

				if (dp[0][i - 1] + a + b < dp[1][i - 1] + 2 * a + b)
					dp[0][i] = dp[0][i - 1] + a + b;
				else
					dp[0][i] = dp[1][i - 1] + 2 * a + b;

				if (ban[i])
					dp[0][i] = INF;
			}
		}


		cout << dp[0][n]<< endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1207/problem/C
 */
