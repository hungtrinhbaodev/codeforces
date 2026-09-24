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
		string s, t;
		vector<int> lets(26,0), lett(26,0);
		cin >> s >> t;

		for (int i = 0; i < s.length(); i++)
			lets[(int)s[i] - 97]++;

		for (int i = 0; i < t.length(); i++)
			lett[(int)t[i] - 97]++;


		bool ac = true;

		for (int i = 0; i < 26; i++)
		{
			if (lett[i] && !lets[i])
				ac = false;
		}


		if (!ac)
			cout << -1 << endl;
		else
		{
			vector<vector<int>> a(26);
			vector<int> used(26, 0);

			for (int i = 0; i < s.length(); i++)
			{
				a[(int)s[i] - 97].push_back(i);
			}

			int i = 0,res = 0;

			while (i < t.length())
			{
				int pos = -1;

				while (i < t.length())
				{
					int d = (int)t[i] - 97;
					vector<int>::iterator it = upper_bound(a[d].begin(),a[d].end(),pos);
					if (it == a[d].end())
						break;
					else
					{
						pos = a[d][it - a[d].begin()];
					}

					i++;
				}

				for (int j = 0; j < 26; j++)
					used[j] = 0;

				res++;
			}

			cout << res << endl;
		}
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1295/problem/C
 */
