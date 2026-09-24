#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
		LL a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a <= b)
			cout << b << endl;
		else
		{
			if (d >= c)
				cout << -1 << endl;
			else
			{
				if ((a - b) % (c - d) == 0)
					cout << b + (a - b) / (c - d) * c << endl;
				else
					cout << b + ((a - b) / (c - d) + 1) * c << endl;
			}
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1354/problem/A
 */
