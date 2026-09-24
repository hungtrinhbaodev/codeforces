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

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a, b;
	vector<pair<int, int>> res;
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		a.push_back(tv);
		b.push_back(tv);

		for (int j = 0; j < m; j++)
		{
			int ti;
			cin >> ti;
			a[i].push_back(ti);
			b[i].push_back(0);
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int count = 0;
			count += a[i][j] + a[i + 1][j + 1] + a[i][j + 1] + a[i + 1][j];
			if (count == 4)
			{
				res.push_back(make_pair(i + 1, j + 1));
				b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
			}
		}
	}

	bool ac = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << b[i][j] << " ";
			if (a[i][j] != b[i][j])
				ac = false;
		}
		//cout << endl;
	}


	if (!ac)
		cout << -1 << endl;
	else
	{
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i].first << " " << res[i].second << endl;
	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1207/problem/B
 */
