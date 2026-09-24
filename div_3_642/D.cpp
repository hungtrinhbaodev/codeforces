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



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<int, set<int>> Map;
		priority_queue<int> Q;
		vector<int> res(n, 0);

		Map[n].insert(0);
		Q.push(n);
		int i = 0;
		while (i < n)
		{
			int lenght = Q.top();
			Q.pop();

			map<int, set<int>>::iterator it = Map.find(lenght);

			if (lenght % 2 == 0)
			{
				set<int>::iterator it_ = it->second.begin();
				int l = *it_;
				int r = l + lenght - 1;

				res[(r + l - 1) / 2] = i + 1;

				it->second.erase(it_);
				if (it->second.empty())
					Map.erase(it);


				Map[lenght / 2 - 1].insert(l);
				Map[lenght / 2].insert((r + l - 1) / 2 + 1);
				Q.push(lenght / 2 - 1);
				Q.push(lenght / 2);
			}
			else
			{
				set<int>::iterator it_ = it->second.begin();
				int l = *it_;
				int r = l + lenght - 1;

				res[(r + l) / 2] = i + 1;

				it->second.erase(it_);
				if (it->second.empty())
					Map.erase(it);


				Map[lenght / 2].insert(l);
				Map[lenght / 2].insert((r + l) / 2 + 1);
				Q.push(lenght / 2);
				Q.push(lenght / 2);
			}

			i++;
		}

		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1353/problem/D
 */
