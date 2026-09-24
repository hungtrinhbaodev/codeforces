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
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			a.push_back(make_pair(t1, t2));
		}


		if (a[0].first < a[0].second)
			cout << "NO" << endl;
		else
		{
			bool ac = true;
			for (int i = 1; i < n && ac; i++)
			{
				int f = a[i].first - a[i - 1].first;
				int d = a[i].second - a[i - 1].second;

				if (a[i].first < a[i].second)
					ac = false;
				else
				{
					if (f < 0 || d < 0)
						ac = false;
					else
					{
						if (f < d)
							ac = false;
					}
				}
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
 * link contest: https://codeforces.com/contest/1334/problem/A
 */
