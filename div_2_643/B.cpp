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
		int n;
		cin >> n;
		vector<int> count(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			count[ti]++;
		}
		int res = 0;
		int mod = 0;
		for (int i = 1; i <= n; i++)
		{
			res += (count[i] + mod) / i;
			mod = (count[i] + mod) % i;
		}
		cout << res << endl;
	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1355/problem/B
 */
