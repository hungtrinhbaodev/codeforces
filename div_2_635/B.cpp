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
		LL x, n, m;
		cin >> x >> n >> m;
		for (int i = 0; i < n; i++)
		{
			if (x <= 20)
				break;
			x = x / 2 + 10;
		}

		if (x <= m * 10)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1337/problem/B
 */
