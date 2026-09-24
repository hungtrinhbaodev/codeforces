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
		int n;
		cin >> n;
		int sum0 = 0, sum1 = 0, res = module;
		vector<int> a;
		for (int i = 0; i < 2 * n; i++)
		{
			int ti;
			cin >> ti;

			if (ti == 1)
				sum0++;
			else
				sum1++;

			a.push_back(ti);
		}


		int k = sum0 - sum1;

		if (k == 0)
			cout << 0 << endl;
		else
		{
			int sum = 0;
			map<int, int> m;
			for (int i = n; i < 2 * n; i++)
			{
				if (a[i] == 1)
					sum++;
				else
					sum--;

				if (m.empty())
					m[sum] = i;
				else
				{
					map<int, int>::iterator it = m.find(sum);

					if (it == m.end())
						m[sum] = i;
				}

				if (sum == k)
					if (res > i - n + 1)
						res = i - n + 1;
			}
			/*
			map<int, int>::iterator it;
			for (it = m.begin(); it != m.end(); it++)
				cout << it->first << " " << it->second << endl;
			*/
			sum = 0;
			for (int i = n - 1; i > -1; i--)
			{
				if (a[i] == 1)
					sum++;
				else
					sum--;

				map<int, int>::iterator it = m.find(k - sum);


				if (it != m.end())
				{
					if (it->second - i + 1 < res)
						res = it->second - i + 1;
				}

				if (sum == k)
					if (res > n - i)
						res = n - i;
			}

			cout << res << endl;
		}

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1278/problem/C
 */
