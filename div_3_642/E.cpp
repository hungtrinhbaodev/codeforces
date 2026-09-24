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
		int n, k, count0 = 0, count1 = 0;
		string s;
		cin >> n >> k >> s;
		vector<string> a(k);


		for (int i = 0; i < n; i++)
		{
			a[i % k].push_back(s[i]);
			if (s[i] == '0')
				count0++;
			else
				count1++;
		}

		LL min = module;
		for (int i = 0; i < k; i++)
		{
			int tmpC1 = 0;
			for (int j = 0; j < a[i].size(); j++)
				if (a[i][j] == '1')
					tmpC1++;

			int res = count1 - tmpC1;
			
			vector<vector<int>> dp;

			for (int j = 0;j < a[i].size(); j++)
			{
				vector<int> t(3, module);
				dp.push_back(t);
			}

			if (a[i][0] == '0')
			{
				dp[0][1] = 0;
				dp[0][2] = 1;
			}
			else
			{
				dp[0][1] = 1;
				dp[0][2] = 0;
			}

			for (int j = 1; j < a[i].size(); j++)
			{
				if (a[i][j] == '0')
				{
					if (dp[j - 1][2] < dp[j - 1][0])
						dp[j][0] = dp[j - 1][2];
					else
						dp[j][0] = dp[j - 1][0];

					if (dp[j - 1][2] + 1 < dp[j - 1][1] + 1)
						dp[j][2] = dp[j - 1][2] + 1;
					else
						dp[j][2] = dp[j - 1][1] + 1;

					dp[j][1] = dp[j - 1][1];
				}
				else
				{
					if (dp[j - 1][2] + 1 < dp[j - 1][0] + 1)
						dp[j][0] = dp[j - 1][2] + 1;
					else
						dp[j][0] = dp[j - 1][0] + 1;

					if (dp[j - 1][2] < dp[j - 1][1])
						dp[j][2] = dp[j - 1][2];
					else
						dp[j][2] = dp[j - 1][1];

					dp[j][1] = dp[j - 1][1] + 1;
				}
			}

			int Min = module;
			//cout << res << endl;
			for (int j = 0; j < 3; j++)
			{
				if (dp[dp.size() - 1][j] < Min)
					Min = dp[dp.size() - 1][j];
				//cout << dp[dp.size() - 1][j] << endl;
			}

			//cout << res + Min << endl;
			if (res + Min < min)
				min = res + Min;
		}

		cout << min << endl;
	}
	
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1353/problem/E
 */
