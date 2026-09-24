#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define LL long long int
#define module 998244353
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
		int a, b, c,res = 0;
		cin >> a >> b >> c;

		//set 1
		if (a > 0)
		{
			a--;
			res++;
		}

		if (b > 0)
		{
			b--;
			res++;
		}

		if (c > 0)
		{
			c--;
			res++;
		}



		//set 2
		if (a > 0)
		{
			if (a - 0 == 1)
			{
				if (b > c)
				{
					if (b > 0)
					{
						res++;
						b--;
						a--;
					}
				}
				else
				{
					if (c > 0)
					{
						res++;
						a--;
						c--;
					}

				}
			}
			else
			{
				if (b > 0)
				{
					res++;
					a--;
					b--;
				}

				if (c > 0)
				{
					res++;
					a--;
					c--;
				}
			}
		}


		if (c > 0)
		{
			if (b > 0)
			{
				res++;
				b--;
				c--;
			}
		}

		//cout << a << " " << b << " " << c << endl;
		//set 3
		if (a > 0 && b > 0 && c > 0)
			res++;


		cout << res << endl;

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1313/problem/A
 */
