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
		int n, k, count = 0;
		cin >> n >> k;
		vector<int> a(101,0);
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a[ti]++;
		}

		for (int i = 0; i < 101; i++)
		{
			if (a[i] > 0)
				count++;
		}

		if (count > k)
		{
			cout << -1 << endl;
		}
		else
		{
			vector<int> res;
			for (int i = 0; i < 101; i++)
			{
				if (a[i] > 0)
					res.push_back(i);
			}

			while (res.size() < k)
			{
				res.push_back(1);
			}

			cout << n * k << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < k; j++)
					cout << res[j] << " ";
			}

			cout << endl;
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1348/problem/B
 */
