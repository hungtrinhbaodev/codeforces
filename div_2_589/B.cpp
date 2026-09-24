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
	vector<vector<int>> graph;
	vector<int> r, c;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		r.push_back(ti);
	}

	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		c.push_back(ti);
	}

	for (int i = 0; i < n + 1; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
		for (int j = 0; j < m + 1; j++)
		{
			graph[i].push_back(0);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < r[i]; j++)
		{
			graph[i][j] = 1;
		}
		graph[i][r[i]] = -1;
	}

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	*/
	bool ac = true;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < c[i]; j++)
		{
			if (graph[j][i] == -1)
				ac = false;
			else
				graph[j][i] = 1;
		}

		if (graph[c[i]][i] == 1)
			ac = false;
		else
			graph[c[i]][i] = -1;
	}

	if (!ac)
		cout << 0 << endl;
	else
	{
		LL res = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 0)
				{
					res *= 2;
					res %= module;
				}
			}

		}

		cout << res << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1228/problem/B
 */
