#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#define LL long long int
#define module 998244353
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
		LL x, y, a, b;

		cin >> x >> y >> a >> b;

		if ((y - x) % (a + b) == 0)
			cout << (y - x) / (a + b) << endl;
		else
			cout << -1 << endl;

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1304/problem/A
 */
