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
		int a, b, c;
		cin >> a >> b >> c;
		if (a >= c)
			cout << -1 << " " << b << endl;
		else if (c / b >= a)
			cout << 1 << " " << -1 << endl;
		else
		{
			cout << 1 << " " << b << endl;
		}
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1373/problem/A
 */
