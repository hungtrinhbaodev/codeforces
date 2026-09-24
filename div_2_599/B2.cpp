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
		vector<pair<int, int>> res;
		vector<int> letter(26, 0);
		int n;
		string s, t;
		cin >> n >> s >> t;

		for (int i = 0; i < n; i++)
		{
			letter[(int)s[i] - 97]++;
			letter[(int)t[i] - 97]++;
		}

		bool ac = true;

		for (int i = 0; i < 26 && ac; i++)
		{
			if (letter[i] % 2)
				ac = false;
		}

		if (!ac)
			cout << "No" << endl;
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (s[i]!=t[i])
				{
					int pos1 = -1, pos2 = -1;
					
					for (int j = i + 1; j < n; j++)
					{
						if (s[j] == s[i])
						{
							pos1 = j;
						}
						
						if (t[j] == s[i])
						{
							pos2 = j;
						}
					}

					if (pos1 != -1)
					{
						swap(s[pos1], t[i]);
						res.push_back(make_pair(pos1 + 1, i + 1));
					}
					else
					{
						swap(t[pos2], s[n - 1]);
						swap(s[n - 1], t[i]);
						res.push_back(make_pair(n, pos2 + 1));
						res.push_back(make_pair(n, i + 1));
					}

				}
			}

			cout << "Yes" << endl;
			cout << res.size() << endl;

			for (int i = 0; i < res.size(); i++)
				cout << res[i].first << " " << res[i].second << endl;


		}

	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1243/problem/B2
 */
