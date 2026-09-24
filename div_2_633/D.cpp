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

int n;
vector<vector<int>> graph;

LL maxDFS(int pos, int Father)
{
	if (graph[pos].size() == 1)
		return -1;

	LL res = 0;
	bool hasLeaf = false;

	for (int i = 0; i < graph[pos].size(); i++)
	{
		int u = graph[pos][i];
		if (u != Father)
		{
			LL ti = maxDFS(u, pos);

			if (ti == -1)
			{
				if (!hasLeaf)
				{
					res++;
					hasLeaf = true;
				}
			}
			else
			{
				res += ti + 1;
			}
		}
	}
	
	return res;
}

bool minDFS(int pos, int Father, int path, int & root)
{
	if (graph[pos].size() == 1 && pos != root)
	{
		if (path % 2 == 0)
			return true;
		else
			return false;
	}

	bool ac = false;

	for (int i = 0; i < graph[pos].size(); i++)
	{
		int u = graph[pos][i];
		if (u != Father)
		{
			ac |= minDFS(u, pos, path + 1, root);
		}
	}

	return ac;
}


int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

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

		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	int leaf, notLeaf;

	for (int i = 0; i < n; i++)
	{
		if (graph[i].size() == 1)
			leaf = i;
		else
			notLeaf = i;
	}

	if (minDFS(leaf, -1, 1, leaf))
		cout << 3 << " ";
	else
		cout << 1 << " ";

	cout<< maxDFS(notLeaf, -1) << endl;


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1339/problem/D
 */
