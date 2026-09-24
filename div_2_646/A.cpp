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
		int n, x , counteven =0, countodd = 0;
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			if (ti % 2 == 0)
				counteven++;
			else
				countodd++;
		}

		if (x >= counteven)
		{
			if (counteven >= 1)
			{
				if ((x - counteven) % 2 != 0)
					x = x - counteven;
				else
					x = x - counteven + 1;


				if (countodd >= x)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
			else
			{
				if (x % 2 == 0)
					cout << "No" << endl;
				else
					cout << "Yes" << endl;
			}

		}
		else
		{
			if (countodd >= 1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}

	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1363/problem/A
 */
