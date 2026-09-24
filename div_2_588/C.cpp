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

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (n <= 6)
		cout << m << endl;
	else
	{

		int max = 0;
		for (int i = 0; i < 7; i++)
		{
			// bo canh i ra ngoai
			int res = 0;
			vector<int> map(7,0);
			set<vector<int>> Set;
			int v = 0;
			for (int j = 0; j < 7; j++)
			{
				if (i != j)
				{
					map[j] = v;
					v++;
				}
			}

			for (int j = 0; j < n; j++)
			{
				if (j != i)
				{

					for (int k = 0; k < graph[j].size();k++)
					{
						int u = graph[j][k];
						vector<int> tv;
						if (u != i)
						{
							tv.push_back(map[j]);
							tv.push_back(map[u]);
							sort(tv.begin(), tv.end());
							Set.insert(tv);
						}
					}
				}
			}

			set<vector<int>>::iterator it;

			res += Set.size();

			for (int j = 0; j < 6; j++)
			{
				int temp = 0;
				for (int k = 0; k < graph[i].size(); k++)
				{
					int u = graph[i][k];

					vector<int> tv;

					tv.push_back(j);
					tv.push_back(map[u]);

					sort(tv.begin(), tv.end());

					set<vector<int>>::iterator it = Set.find(tv);

					if (it == Set.end())
						temp++;
				}

				if (res + temp > max)
					max = res + temp;
			}
		}

		cout << max << endl;
	}

//	system("pause");

	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1230/problem/C
 */
