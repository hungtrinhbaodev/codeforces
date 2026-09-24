#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define MAXSIZE 101
#define MAXSUM 1002
#define pi acos(-1)
#define LL long long int
#define module 1000000007
using namespace std;




int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, m;
		cin >> n >> k >> m;
		if (n / m > k)
			cout << k << endl;
		else
		{
			int d = (k - n / m);
			if (d % (m - 1) == 0)
				cout << n/m - d / (m - 1) << endl;
			else
				cout << n/m - d / (m - 1) - 1 << endl;

		}
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1359/problem/A
 */
