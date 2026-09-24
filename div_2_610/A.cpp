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
		int a, b, c, r;
		cin >> a >> b >> c >> r;

		if (a > b)
			swap(a, b);

		if (c < a)
		{
			if (c + r < a)
				cout << b - a << endl;
			else if (c + r < b)
				cout << b - (c + r) << endl;
			else
				cout << 0 << endl;

		}
		else if (c > b)
		{
			if (c - r > b)
				cout << b - a << endl;
			else if (c - r > a)
				cout << (c - r) - a << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			if (c - r < a)
			{
				if (r + c > b)
					cout << 0 << endl;
				else
					cout << b - (c + r) << endl;
			}
			else
			{
				if (r + c > b)
					cout << c - r - a << endl;
				else
					cout << (c - r - a) + b - (c + r) << endl;
			}
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1282/problem/A
 */
