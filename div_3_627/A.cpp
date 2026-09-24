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
		vector<int> a;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}


		bool ac = true;

		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
				ac = false;
		}

		if (ac)
			cout << "YES" << endl;
		else
		{
			ac = true;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 2 == 1)
					ac = false;
			}

			if (ac)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1324/problem/A
 */
