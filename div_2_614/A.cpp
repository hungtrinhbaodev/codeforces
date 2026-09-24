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
		int n, k, s;
		bool ac = false;
		cin >> n >> s >> k;
		vector<int> a;

		for (int i = 0; i < k; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);

			if (ti == s)
				ac = true;
		}


		if (!ac)
			cout << 0 << endl;
		else
		{
			int d = s - 1, res = module;

			while (d > 0)
			{
				bool ac = false;

				for (int i = 0; i < k && !ac; i++)
					if (a[i] == d)
						ac = true;

				if (!ac)
					break;

				d--;
			}

			if (d >= 1)
				res = s - d;

			d = s + 1;

			while (d <= n)
			{
				bool ac = false;

				for (int i = 0; i < k && !ac; i++)
					if (a[i] == d)
						ac = true;

				if (!ac)
					break;

				d++;
			}

			if (d <= n)
				if (res > d - s)
					res = d - s;

			cout << res << endl;
		}
	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1293/problem/A
 */
