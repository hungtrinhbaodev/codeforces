#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
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
		LL n, m, k, res = -1;

		vector<LL> a;
		cin >> n >> m >> k;

		for (LL i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}


		if (m > k + 1)
		{
			for (LL i = 0; i <= k; i++)
			{
				LL l = i, r = k - i, min = 1;
				min <<= 32;

				for (LL j = 0; j <= m - k - 1; j++)
				{
					int l1 = j, r1 = m - k - 1 - j;
					LL max;


					if (a[l + l1] > a[n - 1 - r - r1])
						max = a[l + l1];
					else
						max = a[n - 1 - r - r1];

					if (max < min)
						min = max;

				}
				if (min > res)
					res = min;
			}

			cout << res << endl;
		}
		else
		{
			vector<int> b;
			for (int i = 0; i < m; i++)
			{
				b.push_back(a[i]);
				b.push_back(a[n - 1 - i]);
			}

			sort(b.begin(), b.end());

			cout << b[b.size() - 1] << endl;
		}

	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1291/problem/C
 */
