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
		LL x;
		string s;
		cin >> x >> s;
		
		LL res = s.size();

		LL i = 0;

		while (i < x)
		{
			LL d = res - (i + 1), k = (LL)((int)s[i] - 48);

			//cout << k<<" "<<res << endl;

			if (d < 0)
				d += module;

			d = (d * (k - 1)) % module;

			res = (res + d) % module;

			string ts;
			int n = s.size();
			if (k != 1 && s.size() <= x)
			{
				for (int j = i + 1; j < n; j++)
				{
					ts.push_back(s[j]);
				}
			}

			if (k == 2)
			{
				int pos = 0;
				while (pos < ts.size() && s.size() <= x)
				{
					s.push_back(ts[pos]);
					pos++;
				}
			}
			else if (k == 3)
			{
				int pos = 0;
				while (pos < ts.size() && s.size() <= x)
				{
					s.push_back(ts[pos]);
					pos++;
				}

				pos = 0;
				while (pos < ts.size() && s.size() <= x)
				{
					s.push_back(ts[pos]);
					pos++;
				}
			}

			i++;
		}
		cout << res << endl;
	}



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1281/problem/C
 */
