#include<iostream>
#include<vector>
#include<algorithm>
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
		vector<bool> b(1000, false);
		vector<LL> a;

		int n, k;
		cin >> n >>k;

		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;

			a.push_back(ti);
		}

		bool ac = true;

		for (int i = 0; i < n && ac; i++)
		{
			LL ti = a[i];
			int pos = 0;
			while (ac)
			{
				if (ti % k == 0 || ti % k == 1)
				{
					if (ti % k == 1)
						if (b[pos])
							ac = false;
						else
							b[pos] = true;
				}
				else
					ac = false;

				pos++;
				ti /= k;
				if (!ti)
					break;
			}
		}

		if (ac)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1312/problem/C
 */
