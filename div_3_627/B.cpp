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
		vector<vector<int>> a;
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			vector<int> tv;
			a.push_back(tv);
		}

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a[ti].push_back(i);
		}


		bool ac = false;

		for (int i = 1; i <= n && !ac; i++)
		{
			if (a[i].size() > 2)
				ac = true;
			else
			{
				if (a[i].size() == 2)
				{
					if (a[i][1] - a[i][0] != 1)
						ac = true;
				}
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
 * link contest: https://codeforces.com/contest/1324/problem/B
 */
