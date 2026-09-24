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
	LL n, m;
	cin >> n >> m;
	vector<LL> dp1(n + 1, 0), dp2(m + 1, 0);
	dp1[0] = dp1[1] = 1;
	dp2[0] = dp2[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp1[i] = (dp1[i - 1] + dp1[i - 2]) % module;
	}
	for (int i = 2; i <= m; i++)
	{
		dp2[i] = (dp2[i - 1] + dp2[i - 2]) % module;
	}
	
	LL res = 2*dp1[n] + 2*dp2[m] - 2;
	cout << res % module << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1248/problem/C
 */
