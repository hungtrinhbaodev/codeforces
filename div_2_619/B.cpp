#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
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
		vector<LL> a, b;
		int n, m = -1, count = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			if (ti == -1)
				count++;
			a.push_back(ti);
		}

		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				if (a[i] == -1 && a[i + 1] != -1)
					b.push_back(a[i + 1]);
			}
			else if (i == n - 1)
			{
				if (a[i] == -1 && a[i - 1] != -1)
					b.push_back(a[i - 1]);
			}
			else
			{
				if (a[i] == -1)
				{
					if (a[i - 1] != -1)
						b.push_back(a[i - 1]);

					if (a[i + 1] != -1)
						b.push_back(a[i + 1]);
				}
			}
		}

		int min, max;

		if (b.size() == 0)
			min = max = 0;
		else
			min = max = b[0];

		for (int i = 1; i < b.size(); i++)
		{
			if (max < b[i])
				max = b[i];

			if (min > b[i])
				min = b[i];
		}

		int k = (min + max) / 2;

		for (int i = 0; i < n; i++)
		{
			if (a[i] == -1)
				a[i] = k;
		}

		for (int i = 0; i < n - 1; i++)
		{
			if (m < abs(a[i] - a[i + 1]))
				m = abs(a[i] - a[i + 1]);
		}

		cout << m << " " << k << endl;
	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1301/problem/B
 */
