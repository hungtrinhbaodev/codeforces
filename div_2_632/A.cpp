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
		int n, m;
		cin >> n >> m;

		vector<vector<char>> a;

		for (int i = 0; i < n; i++)
		{
			vector<char> tc;
			a.push_back(tc);

			for (int j = 0; j < m; j++)
			{
				a[i].push_back('W');
			}
		}



		for (int i = 0; i < m; i++)
		{
			a[0][i] = 'B';
		}

		for (int i = 0; i < n; i++)
		{
			a[i][0] = 'B';
		}

		a[1][0] = 'B';

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << a[i][j];
			}
			cout << endl;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1333/problem/A
 */
