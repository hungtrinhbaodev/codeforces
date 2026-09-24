#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define LL long long int
#define module 998244353
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> graph;
	vector<int> res;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
	}

	for (int i = 0; i < n - 1; i++)
	{
		res.push_back(0);
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		graph[u].push_back(i);
		graph[v].push_back(i);
	}

	int countLeaf = 0;
	vector<int> tvLeaf;

	for (int i = 0; i < n; i++)
	{
		if (graph[i].size() == 1)
		{
			countLeaf++;
			tvLeaf.push_back(graph[i][0]);

			if (countLeaf == 3)
				break;
		}
	}

	if (countLeaf == 2)
	{
		for (int i = 0; i < n - 1; i++)
			cout << i << endl;
	}
	else
	{
		for (int i = 0; i < countLeaf; i++)
		{
			res[tvLeaf[i]] = i;
		}

		int pos = 3;
		for (int i = 0; i < n - 1; i++)
		{
			if (i != tvLeaf[0] && i != tvLeaf[1] && i != tvLeaf[2])
			{
				res[i] = pos;
				pos++;
			}
		}

		for (int i = 0; i < n - 1; i++)
			cout << res[i] << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1325/problem/C
 */
