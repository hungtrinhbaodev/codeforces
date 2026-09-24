#include<iostream>
#include<vector>
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
		int n, m;
		cin >> n >> m;
		if ((n - m) % m == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1312/problem/A
 */
