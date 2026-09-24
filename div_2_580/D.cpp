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

vector<vector<int>> graph;
vector<int> visited;
vector<int> trace;

int BFS(int u, int v)
{
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i] = false;
		trace[i] = -1;
	}

	queue<int> Q;
	Q.push(u);
	int count = 0;
	trace[u] = -1;
	visited[u] = true;
	int k = 0 ,pos = u;
	
	while (!Q.empty())
	{
		int pos = Q.front();

		if (pos == v)
			break;

		Q.pop();
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[pos][i])
			{
				if (!visited[i])
				{
					trace[i] = pos;
					visited[i] = true;
					Q.push(i);
				}
			}
		}
	}

	if (trace[v] != -1)
	{
		int i = v;

		while (i != -1)
		{
			i = trace[i];
			count++;
		}
	}

	return count;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	



	int n;
	cin >> n;
	vector<LL> a;
	vector<int> count(62);
	bool ac = true;
	for (int i = 0; i < n && ac; i++)
	{
		LL ti;
		cin >> ti;

		if(ti != 0)
			a.push_back(ti);

		int j = 0;
		while (ti > 0 && ac)
		{
			if (ti & 1)
			{
				count[j]++;
				if (count[j] >= 3)
					ac = false;
			}
			j++;
			ti >>= 1;
		}
	}
	if (!ac)
		cout << 3 << endl;
	else
	{

		// Tao graph
		for (int i = 0; i < a.size(); i++)
		{
			vector<int> tv;
			graph.push_back(tv);
			visited.push_back(0);
			trace.push_back(0);
			for (int j = 0; j < a.size(); j++)
			{
				graph[i].push_back(0);
			}
		}


		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (a[i] & a[j])
				{
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
			}
		}
		/*
		for (int i = 0; i < graph.size(); i++)
		{
			cout << i << ": ";
			for (int j = 0; j < graph[i].size(); j++)
				cout << graph[i][j] << " ";

			cout << endl;
		}
		*/
		int min = module;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (graph[i][j])
				{
					graph[i][j] = 0;
					graph[j][i] = 0;

					int  t = BFS(i, j);

					graph[i][j] = 1;
					graph[j][i] = 1;

					if (t > 2 && t < min)
						min = t;
				}
			}
		}

		if (min == module)
			cout << -1 << endl;
		else
			cout << min << endl;

	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1206/problem/D
 */
