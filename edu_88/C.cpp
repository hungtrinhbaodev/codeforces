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
		double h, c, t2, res1 = 0,res2 = 0,res3 = module;
		int m;
		cin >> h >> c >> t2;

		res1 = fabs((h + c) / 2 - t2);
		res2 = fabs(t2 - h);

		if ((h + c) < 2 * t2)
		{
			double d = 2 * t2 - (h + c);
			int k = (h - c) / d;

			double min = module;
			for (int i = k + 2; i >= k - 2; i--)
			{
				if (i > 0 && i % 2 == 1)
				{
					if (abs(((h + c) + (h - c) / i) / 2 - t2) <= min)
					{
						min = abs(((h + c) + (h - c) / i) / 2 - t2);
						m = i;
					}
				}
			}

			res3 = min;
		}

		//cout << ((h + c) + (h - c) / 3) / 2 << endl;
		if (res1 <= res2 && res1 <= res3)
			cout << 2 << endl;
		else if (res2 <= res1 && res2 <= res3)
			cout << 1 << endl;
		else
			cout << m << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1359/problem/C
 */
