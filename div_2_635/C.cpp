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

vector<vector<int>> graph;
vector<LL> value;
int n, k;

bool SS(LL& a, LL& b)
{
	return a > b;
}

LL DFS(int pos, int isFahter, int rank, int root)
{
	if (graph[pos].size() == 1 && pos != root)
	{
		value[pos] = rank;
		return 1;
	}

	LL child = 0;
	value[pos] = rank;
	for (int i = 0; i < graph[pos].size(); i++)
	{
		int u = graph[pos][i];
		if (u != isFahter)
		{
			child += DFS(u, pos, rank + 1, root);
		}
	}

	value[pos] -= child;
	return child + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
		value.push_back(0);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(0, -1, 0, 0);

	sort(value.begin(), value.end(),SS);

	LL res = 0;
	for (int i = 0; i < k; i++)
	{
		res += value[i];
	}

	cout << res << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1337/problem/C
 */
