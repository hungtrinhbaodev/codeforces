#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
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
		vector<vector<int>> graph;
		int n, m;

		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			vector<int> tv;
			graph.push_back(tv);

			for (int j = 0; j < m; j++)
			{
				char tc;
				cin >> tc;

				if (tc == 'P')
					graph[i].push_back(0);
				else
					graph[i].push_back(1);
			}
		}


		bool A = true, P = true;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 1)
					P = false;

				if (graph[i][j] == 0)
					A = false;
			}
		}

		if (P)
			cout << "MORTAL" << endl;
		else if (A)
			cout << 0 << endl;
		else
		{
			// Xet tren dong
			int res = -1;
			for (int i = 0; i < n; i++)
			{
				bool ac = true;

				for (int j = 0; j < m && ac; j++)
				{
					if (graph[i][j] == 0)
						ac = false;
				}

				if (ac)
				{
					if (i == 0 || i == n - 1)
						res = 1;
					else if(res != 1)
						res = 2;
				}
			}

			// xet tren cot
			for (int i = 0; i < m; i++)
			{
				bool ac = true;

				for (int j = 0; j < n && ac; j++)
				{
					if (graph[j][i] == 0)
						ac = false;
				}

				if (ac)
				{
					if (i == 0 || i == m - 1)
						res = 1;
					else if (res != 1)
						res = 2;
				}
			}

			if (res != -1)
				cout << res << endl;
			else
			{
				// xet tren o

				//xet 4 goc ma tran
				if (graph[0][0] == 1 || graph[0][m - 1] == 1 || graph[n - 1][0] == 1 || graph[n - 1][m - 1] == 1)
					cout << 2 << endl;
				else
				{
					// xet dong dau dong cuoi co ton tai 1 o nao ko
					bool ac = false;
					for (int i = 0; i < m && !ac; i++)
					{
						if (graph[0][i] == 1)
							ac = true;

						if (graph[n - 1][i] == 1)
							ac = true;
					}

					// xet cot dau cot cuoi co ton tai 1 o nao ko
					for (int i = 0; i < n && !ac; i++)
					{
						if (graph[i][0] == 1)
							ac = true;

						if (graph[i][m - 1] == 1)
							ac = true;
					}


					if (ac)
						cout << 3 << endl;
					else
						cout << 4 << endl;
				}
			}
		}
	}



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1281/problem/D
 */
