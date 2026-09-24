#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
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
		LL a, b, c, d, x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		bool ac1 = false, ac2 = false;

		if (a > b)
		{
			if (x - x1 >= a - b)
				ac1 = true;
		}
		else if (a < b)
		{
			if (x2 - x >= b - a)
				ac1 = true;
		}
		else
		{
			if (x1 != x2)
				ac1 = true;
			else if (a == 0 && b == 0)
				ac1 = true;

		}


		if (c > d)
		{
			if (y - y1 >= c - d)
				ac2 = true;
		}
		else if (c < d)
		{
			if (y2 - y >= d - c)
				ac2 = true;
		}
		else
		{
			if (y1 != y2)
				ac2 = true;
			else if (c == 0 && d == 0)
				ac2 = true;
		}

		if (ac1 && ac2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1332/problem/A
 */
