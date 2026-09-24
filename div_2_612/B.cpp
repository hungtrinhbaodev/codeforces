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

	map<string, int> s;
	set <set<int>> res;

	vector<string> a;
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string ts;
		cin >> ts;
		a.push_back(ts);
		s[ts] = i;
	}


	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			string ts;
			for (int k = 0; k < m; k++)
			{
				if (a[j][k] == a[i][k])
				{
					ts.push_back(a[j][k]);
				}
				else
				{
					if ((a[j][k] == 'T' && a[i][k] == 'S' )||( a[j][k] == 'S' && a[i][k] == 'T'))
						ts.push_back('E');
					else if ((a[j][k] == 'E' && a[i][k] == 'S') ||( a[j][k] == 'S' && a[i][k] == 'E'))
						ts.push_back('T');
					else
						ts.push_back('S');
				}
			}

			map<string, int>::iterator it = s.find(ts);
			if (it != s.end())
			{
				set<int> t;
				t.insert(i);
				t.insert(j);
				t.insert(it->second);
				res.insert(t);
			}

		}
	}

	cout << res.size() << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1287/problem/B
 */
