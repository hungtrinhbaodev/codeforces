#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
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
		LL n, x, y;
		cin >> n >> x >> y;
		if (x + y == n + 1 && n!=1) 
		{
			cout << 2 << " " << n << endl;
		}
		else
		{
			if (x + y < n + 1)
				cout << 1 << " " << x + y - 1 << endl;
			else
			{
				if ( 2*n - (x + y + 1)  < 0)
					cout << n << " " << n << endl;
				else
					cout << n - (2 * n - (x + y + 1)) << " " << n << endl;
			}
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1313/problem/B
 */
