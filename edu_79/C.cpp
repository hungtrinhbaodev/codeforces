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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> posPresent(n, 0), S, list;
		vector<bool>Optimal(n, false);

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			ti--;
			S.push_back(ti);
			posPresent[ti] = i;
		}

		for (int i = 0; i < m; i++)
		{
			int ti;
			cin >> ti;
			ti--;
			list.push_back(ti);
		}

		LL res = 0, j = 0;

		for (int i = 0; i < m; i++)
		{
			if (Optimal[list[i]])
				res++;
			else
			{

				int k = posPresent[list[i]];
				while (j < k)
				{
					Optimal[S[j]] = true;
					j++;
				}
				j = k;
				res += 2 * (LL)(k - i) + 1;
			}
		}


		cout << res << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1279/problem/C
 */
