#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define pi acos(-1)
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
		int c, r;
		cin >> c >> r;
		if (c % 2 == 0 && r % 2 == 0)
		{
			cout << r * c / 2 << endl;
		}
		else if (c % 2 == 0 && r % 2 != 0)
		{
			cout << c / 2 * r << endl;
		}
		else if (c % 2 != 0 && r % 2 == 0)
		{
			cout << r / 2 * c << endl;
		}
		else
		{
			if ((r - 1) / 2 * c + (c / 2 + 1) > (c - 1) / 2 * r + (r / 2 + 1))
				cout << (c - 1) / 2 * r + (r / 2 + 1) << endl;
			else
				cout << (r - 1) / 2 * c + (c / 2 + 1) << endl;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1358/problem/A
 */
