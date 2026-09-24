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
		int n, m, x, y, res = 0;
		cin >> n >> m >> x >> y;

		for (int i = 0; i < n; i++)
		{
			stack<char> s;
			int count = 0;
			for (int j = 0; j < m; j++)
			{
				char tc;
				cin >> tc;

				if (s.empty())
				{
					if (tc == '.')
						count++;
					s.push(tc);
				}
				else
				{
					if (tc == '*')
					{
						int cost1 = count*x, cost2;
						if (count % 2 == 0)
							cost2 = count / 2 * y;
						else
							cost2 = count / 2 * y + x;

						if (cost1 < cost2)
							res += cost1;
						else
							res += cost2;
						count = 0;
						s.push(tc);
					}
					else 
					{
						count++;
						s.push(tc);
					}
				}
			}
			int cost1 = count * x, cost2;
			if (count % 2 == 0)
				cost2 = count / 2 * y;
			else
				cost2 = count / 2 * y + x;

			if (cost1 < cost2)
				res += cost1;
			else
				res += cost2;
		}

		cout << res << endl;

	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1359/problem/B
 */
