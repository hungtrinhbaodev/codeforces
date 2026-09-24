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

vector<vector<int>> cost(3);
vector<vector<LL>> res(6);
vector<vector<int>> pathRes(6);
vector<vector<int>> graph;


void DFS(int pos,int i, int Father, int root)
{
	
	if (i == 0)
	{
		res[0][i] += cost[0][pos];
		res[1][i] += cost[0][pos];
		res[2][i] += cost[1][pos];
		res[3][i] += cost[1][pos];
		res[4][i] += cost[2][pos];
		res[5][i] += cost[2][pos];

		pathRes[0][pos] = 0;
		pathRes[1][pos] = 0;
		pathRes[2][pos] = 1;
		pathRes[3][pos] = 1;
		pathRes[4][pos] = 2;
		pathRes[5][pos] = 2;
	}
	else if (i == 1)
	{
		res[0][i] += res[0][i - 1] + cost[1][pos];
		res[1][i] += res[1][i - 1] + cost[2][pos];
		res[2][i] += res[2][i - 1] + cost[0][pos];
		res[3][i] += res[3][i - 1] + cost[2][pos];
		res[4][i] += res[4][i - 1] + cost[0][pos];
		res[5][i] += res[5][i - 1] + cost[1][pos];

		pathRes[0][pos] = 1;
		pathRes[1][pos] = 2;
		pathRes[2][pos] = 0;
		pathRes[3][pos] = 2;
		pathRes[4][pos] = 0;
		pathRes[5][pos] = 1;
	}
	else
	{
	
		res[0][i] += res[4][i - 1] + cost[1][pos];
		swap(pathRes[0], pathRes[4]);

		res[1][i] += res[2][i - 1] + cost[2][pos];
		swap(pathRes[1], pathRes[2]);

		res[2][i] += res[5][i - 1] + cost[0][pos];
		swap(pathRes[2], pathRes[5]);

		res[3][i] += res[0][i - 1] + cost[2][pos];
		swap(pathRes[3], pathRes[4]);

		res[4][i] += res[3][i - 1] + cost[0][pos];

		res[5][i] += res[1][i - 1] + cost[1][pos];

		pathRes[0][pos] = 1;
		pathRes[1][pos] = 2;
		pathRes[2][pos] = 0;
		pathRes[3][pos] = 2;
		pathRes[4][pos] = 0;
		pathRes[5][pos] = 1;
	}


	if (graph[pos].size() == 1 && pos != root)
		return;

	for (int j = 0; j < graph[pos].size(); j++)
	{
		
		int u = graph[pos][j];
		if (u != Father)
		{
			DFS(u, i + 1, pos, root);
		}
			
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int ti;
			cin >> ti;
			cost[i].push_back(ti);
		}
	}


	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res[i].push_back(0);
			pathRes[i].push_back(0);
		}
	}

	bool ac = true;

	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
	}


	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		graph[u].push_back(v);
		graph[v].push_back(u);

		if (graph[u].size() > 2 || graph[v].size() > 2)
			ac = false;
	}

	if (!ac)
		cout << -1 << endl;
	else
	{
		int leaf = -1;

		for (int i = 0; i < n; i++)
		{
			if (graph[i].size() == 1)
				leaf = i;
		}


		DFS(leaf, 0, -1, leaf);

		LL pos = 0, max = res[0][n-1];

		for (int i = 1; i < 6; i++)
		{
			if (res[i][n - 1] < max)
			{
				max = res[i][n - 1];
				pos = i;
			}
		}

		cout << res[pos][n - 1] << endl;
		for (int i = 0; i < n; i++)
			cout << pathRes[pos][i] + 1 << " ";
		cout << endl;
	}





	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1244/problem/D
 */
