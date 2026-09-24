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
		int n;
		cin >> n;
		vector<int> check(n, 0),used(n,0);
		vector<int> a;
		vector<pair<int, int>> res;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			ti--;

			
			check[ti]++;
			a.push_back(ti);

		}

		bool ac = true;
		int pos = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (check[i] >= 3 || check[i] < check[i+1])
				ac = false;


			if (check[i] > check[i + 1])
				pos = i;
		}

		if (check[n - 1] >= 3)
			ac = false;


		if (!ac)
			cout << 0 << endl;
		else
		{
			for (int i = 0; i <= pos; i++)
				used[a[i]] = 1;

			ac = true;
			for (int i = 0; i <= pos; i++)
			{
				if (!used[i])
					ac = false;

				used[i] = 0;
			}

			if (ac)
				res.push_back(make_pair(pos + 1, n - pos - 1));


			ac = true;

			for (int i = n - pos - 1; i < n; i++)
				used[a[i]] = 1;

			for (int i = 0; i <= pos; i++)
			{
				if (!used[i])
					ac = false;

				used[i] = 0;
			}

			if (ac && n - pos - 1 != pos + 1)
				res.push_back(make_pair(n - pos - 1, pos + 1));

			cout << res.size() << endl;
			for (int i = 0; i < res.size(); i++)
				cout << res[i].first << " " << res[i].second << endl;

		}
	}

	
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1330/problem/B
 */
