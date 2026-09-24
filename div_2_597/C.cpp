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

	string s;
	cin >> s;

	LL res = 1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'u')
		{
			vector<LL> dp;
			dp.push_back(1);
			dp.push_back(1);

			int count = 0;
			int j = i;
			while (j < s.size() && s[j] == 'u')
				j++;
			count = j - i;
			for (int i = 2; i <= count; i++)
			{
				dp.push_back((dp[i - 1] + dp[i - 2]) % module);
			}
			res *= dp[count];
			res %= module;
			i = j - 1;
		}
		else if (s[i] == 'n')
		{
			vector<LL> dp;
			dp.push_back(1);
			dp.push_back(1);

			int count = 0;
			int j = i;
			while (j < s.size() && s[j] == 'n')
				j++;
			count = j - i;
			for (int i = 2; i <= count; i++)
			{
				dp.push_back((dp[i - 1] + dp[i - 2]) % module);
			}
			res *= dp[count];
			res %= module;
			i = j - 1;
		}
		else if (s[i] == 'm' || s[i] == 'w')
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << res << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1245/problem/C
 */
