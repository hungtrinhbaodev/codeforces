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

vector<string> t;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		vector<int> a;
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}


		bool ac = true;

		for (int i = 0; i < n - 1 && ac; i++)
		{
			if (a[i + 1] - k > a[i])
			{
				int needBlock = a[i + 1] - k - a[i];
				if (needBlock > m)
					ac = false;
				else
					m -= needBlock;
			}
			else
			{
				int d = 0;

				if (a[i + 1] - k > 0)
					d = a[i + 1] - k;

				m += a[i] - d;
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
 * link contest: https://codeforces.com/contest/1200/problem/B
 */
