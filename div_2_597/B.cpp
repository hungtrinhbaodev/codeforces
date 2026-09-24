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
		int n, m, a, b, c, suma = 0, sumb = 0, sumc = 0;
		string s;
		cin >> n;
		cin >> a >> b >> c;
		cin >> s;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'R')
				suma++;
			else if (s[i] == 'P')
				sumb++;
			else
				sumc++;
		}


		if (n % 2 == 0)
			m = n / 2;
		else
			m = n / 2 + 1;

		int res = 0;

		if (a < sumc)
			res += a;
		else
			res += sumc;

		if (b < suma)
			res += b;
		else
			res += suma;

		if (c < sumb)
			res += c;
		else
			res += sumb;
		
		
		if (res < m)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			string sres(n, '#');

			for (int i = 0; i < n; i++)
			{
				if (s[i] == 'R')
				{
					if (b > 0)
					{
						sres[i] = 'P';
						b--;
					}
				}
				else if (s[i] == 'P')
				{
					if (c > 0)
					{
						sres[i] = 'S';
						c--;
					}
				}
				else
				{
					if (a > 0)
					{
						sres[i] = 'R';
						a--;
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (sres[i] == '#')
				{
					if (a > 0)
					{
						sres[i] = 'R';
						a--;
					}
					else if (b > 0)
					{
						sres[i] = 'P';
						b--;
					}
					else
					{
						sres[i] = 'S';
						c--;
					}
				}
			}


			cout << sres << endl;

		}

	}

	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1245/problem/B
 */
