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

	int a, b, c, d;
	string res;
	cin >> a >> b >> c >> d;

	int d1 = b - a, d2 = c - d;

	if (abs(d1 - d2) <= 1 && d1 >= 0 && d2 >= 0)
	{
		while (a)
		{
			res.push_back('0');
			res.push_back('1');
			a--;
			b--;
		}

		int mind;
		if (d1 > d2)
			mind = d2;
		else
			mind = d1;

		while (mind)
		{
			res.push_back('2');
			res.push_back('1');
			b--;
			c--;
			mind--;
		}

		while (d)
		{
			res.push_back('2');
			res.push_back('3');
			c--;
			d--;
		}

		if (d1 - d2 == 1)
			res = '1' + res;
		else if (d2 - d1 == 1)
			res = res + '2';

		cout << "YES" << endl;

		for (int i = 0; i < res.length(); i++)
			cout << res[i] << " ";

		cout << endl;

	}
	else
	{
		if (a == 0 && b == 0 && d - c == 1)
		{
			if (abs(d2) == 1)
			{
				while (c)
				{
					res.push_back('3');
					res.push_back('2');
					c--;
				}
				res.push_back('3');

				cout << "YES" << endl;

				for (int i = 0; i < res.length(); i++)
					cout << res[i] << " ";

				cout << endl;
			}
			else
				cout << "NO" << endl;
		}
		else if (c == 0 && d == 0 && a - b == 1)
		{
			while (b)
			{
				res.push_back('0');
				res.push_back('1');
				b--;
			}
			res.push_back('0');

			cout << "YES" << endl;

			for (int i = 0; i < res.length(); i++)
				cout << res[i] << " ";

			cout << endl;
		}
		else
			cout << "NO" << endl;
	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1265/problem/D
 */
