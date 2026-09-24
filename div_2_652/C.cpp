#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define MAXSIZE 101
#define MAXSUM 1002
#define pi acos(-1)
#define LL long long int
#define module 1000000007
using namespace std;




int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		LL res = 0;
		int n, k;
		cin >> n >> k;
		vector<LL> a, b;
		vector<vector<LL>> c;
		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			a.push_back(ti);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < k; i++)
		{
			int ti;
			cin >> ti;
			b.push_back(ti);
		}
		sort(b.begin(), b.end());
		int pos = 0;
		for (int i = k - 1; i > -1; i--)
		{
			c.push_back(vector<LL>());
			for (int j = 0; j < b[i] - 1; j++)
			{
				c[k - 1 - i].push_back(a[pos]);
				pos++;
			}
		}

		pos = k - 1;
		for (int i = n - 1; i >= n - k; i--)
		{
			c[pos].push_back(a[i]);
			pos--;
		}

		for (int i = 0; i < k; i++)
		{
			res += (c[i][0] + c[i][c[i].size() - 1]);
		}

		cout << res << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1369/problem/C
 */
