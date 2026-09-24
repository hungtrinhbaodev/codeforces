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
		int n, s, k;
		vector<int> a, dp;
		cin >> n >> s >> k;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
			dp.push_back(0);
		}

		a.push_back(0);
		dp.push_back(0);
		sort(a.begin(), a.end());

		int res = -1;
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
				dp[i] = a[i];
			else
			{
				if (dp[i - 2] + a[i] < dp[i - 1] + a[i])
				{
					dp[i] = dp[i - 2] + a[i];
				}
				else
				{
					dp[i] = dp[i - 1] + a[i];
				}
			}

			if (dp[i] > s)
			{
				res = i - 1;
				break;
			}

		}

		if (res == -1)
			cout << n << endl;
		else
			cout << res << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1282/problem/B1
 */
