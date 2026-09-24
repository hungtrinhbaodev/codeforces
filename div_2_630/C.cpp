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
		int n, k, res = 0;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<string> a;

		for (int i = 0; i < k; i++)
		{
			string ts;
			a.push_back(ts);
			for (int j = i; j < n; j += k)
				a[i].push_back(s[j]);
		}

		vector<int> letter(26, 0);

		for (int i = 0; i < a.size() / 2; i++)
		{
			string ts;

			ts = a[i] + a[a.size() - 1 - i];

		
			for (int j = 0; j < ts.size(); j++)
			{
				letter[(int)ts[j] - 97]++;
			}

			int max = 0;

			for (int i = 0; i < 26; i++)
				if (letter[i] > max)
					max = letter[i];

			res += ts.size() - max;

			for (int i = 0; i < 26; i++)
				letter[i] = 0;

		}

		if (a.size() % 2 == 1)
		{
			for (int i = 0; i < a[a.size() / 2].size(); i++)
			{
				letter[(int)a[a.size() / 2][i] - 97]++;
			}

			int max = 0;

			for (int i = 0; i < 26; i++)
				if (letter[i] > max)
					max = letter[i];

			res += a[a.size()/2].size() - max;
		}

		cout << res << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1332/problem/C
 */
