#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
		int n;
		LL res1 = 0, res2 = 0, size1 = 0, size2 = 0;
		vector<LL> a;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			a.push_back(ti);
		}

		int pos = 0, max = 0;
		while (pos < n && a[pos] > 0)
		{
			if (a[pos] > max)
				max = a[pos];
			pos++;
		}

		if (pos == n)
		{
			cout << max << endl;
			continue;
		}

		bool sign = false;
		for (int i = pos; i < n; i++)
		{
			int j = i;
			LL max = -module;
			if (!sign)
			{
				while (j < n && a[j] < 0)
				{
					if (a[j] > max)
						max = a[j];
					j++;
				}
				res1 += max;
				i = j - 1;
				sign = true;
			}
			else
			{
				while (j < n && a[j] > 0)
				{
					if (a[j] > max)
						max = a[j];
					j++;
				}
				res1 += max;
				i = j - 1;
				sign = false;
			}
			size1++;
		}
		
		pos = 0, max = -module;
		while (pos < n && a[pos] < 0)
		{
			if (a[pos] > max)
				max = a[pos];
			pos++;
		}

		if (pos == n)
		{
			cout << max << endl;
			continue;
		}

		sign = true;
		for (int i = pos; i < n; i++)
		{
			int j = i;
			LL max = -module;
			if (!sign)
			{
				while (j < n && a[j] < 0)
				{
					if (a[j] > max)
						max = a[j];
					j++;
				}
				res2 += max;
				i = j - 1;
				sign = true;
			}
			else
			{
				while (j < n && a[j] > 0)
				{
					if (a[j] > max)
						max = a[j];
					j++;
				}
				res2 += max;
				i = j - 1;
				sign = false;
			}
			size2++;
		}

		if (size1 > size2)
			cout << res1 << endl;
		else if (size2 > size1)
			cout << res2 << endl;
		else
		{
			if (size2 > size1)
				cout << res2 << endl;
			else
				cout << res1 << endl;
		}


	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1343/problem/C
 */
