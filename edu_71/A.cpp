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
		int a, b, c, d, e;

		cin >> a >> b >> c >> d >> e;

		if (d > e)
		{
			if (a / 2 > b)
			{
				if (a / 2 - b < c)
					cout << b * d + (a / 2 - b) * e << endl;
				else
					cout << b * d + c * e << endl;
			}
			else
				cout << (a / 2) * d << endl;
		}
		else
		{
			if (a / 2 > c)
			{
				if (a / 2 - c < b)
					cout << c * e + (a / 2 - c) * d << endl;
				else
				{
					cout << c * e + b * d << endl;
				}
			}
			else
				cout << (a / 2) * e << endl;
		}

	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1207/problem/A
 */
