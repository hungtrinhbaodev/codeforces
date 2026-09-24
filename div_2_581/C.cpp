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
vector<int> path, res;
int n, m;

void enter()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
		string s;
		cin >> s;
		for (int j = 0;j < n; j++)
		{
			if(s[j] == '0')
				graph[i].push_back(0);
			else
				graph[i].push_back(1);

		}
	}



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 0 && i != j)
				graph[i][j] = module;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		ti--;
		path.push_back(ti);
	}
}

void Floyd()
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
				{
					graph[i][j] =graph[i][k] +graph[k][j];
				}
			}
		}
	}
}


void sovle()
{
	Floyd();
	res.push_back(path[0] + 1);
	int i = 0;
	while (i < m)
	{
		int pre = path[i];
		int j = i + 1;

		while (j < m)
		{
			if (graph[pre][path[j]] == j - i)
				j++;
			else
				break;
		}

		res.push_back(path[j - 1] + 1);

		if (j == m)
			break;

		i = j - 1;
	}
}

void show()
{
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	enter();
	sovle();
	show();

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1204/problem/C
 */
