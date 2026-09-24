#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

vector<int> res;
vector<int> a;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		LL n, k, c, d, pos = 0;
		string s;
		cin >> n;
		cin >> k;

		for (LL i = 1; i <= 2 * sqrt(k); i++)
		{
			if (i * (i + 1) / 2 <= k)
				pos = i;

		}

		if (pos * (pos + 1) / 2 == k)
		{
			string s;

			for (int i = 0; i < n; i++)
			{
				if (i ==  n - 1 - pos || i == n - pos)
					s += 'b';
				else
					s += 'a';
			}

			cout << s << endl;

		}
		else
		{
			LL d = k - pos * (pos + 1) / 2;

			for (int i = 0; i < n; i++)
			{
				if (i == n - 2 - pos || i == n - d)
					s += 'b';
				else
					s += 'a';
			}

			cout << s << endl;

		}
	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1328/problem/B
 */
