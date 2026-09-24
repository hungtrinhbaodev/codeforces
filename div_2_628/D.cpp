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

	LL a = 0, b = 0, c = 0, u, v, max = 4000000000000000000;

	cin >> u >> v;

	if (u == 0 && v == 0)
		cout << 0 << endl;
	else
	{
		if (v - u < 0 || (v - u) % 2 == 1)
			cout << -1 << endl;
		else
		{
			LL d = v - u, i = 1, j = 2;
			while (j <= max)
			{
				LL e = d & j;
				LL k = u & i;
				//cout << e << " " << k << endl;
				if (k != 0)
				{
					if (e != 0)
					{
						a += i;
						b += i;
						c += i;
					}
					else
					{
						a += i;
					}
				}
				else
				{
					if (e != 0)
					{
						a += i;
						b += i;
					}
				}

				j *= 2;
				i *= 2;
			}

			//cout << a << " " << b << " " << c << endl;
			if (b != 0 && c != 0)
			{
				cout << 3 << endl << a << " " << b << " " << c << endl;
			}
			else
			{
				if (b == 0)
					cout << 1 << endl << a << endl;
				else
					cout << 2 << endl << a << " " << b << endl;
			}

		}
	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1325/problem/D
 */
