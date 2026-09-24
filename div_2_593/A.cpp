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
		int a, b, c;
		cin >> a >> b >> c;

		if (c / 2 >= b)
			cout << b * 3 << endl;
		else
		{
			if ((b - (c / 2)) / 2 >= a)
			{
				cout << 3 * (c / 2) + a * 3 << endl;
			}
			else
			{
				cout << 3 * (c / 2) + (b - (c / 2)) / 2 * 3 << endl;
			}
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1236/problem/A
 */
