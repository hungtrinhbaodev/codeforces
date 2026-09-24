#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
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
		int n, k, res = 0;
		string s;

		cin >> n >> k;
		cin >> s;
		int f = 0, l = s.length() - 1;
		while (f < n && s[f] == '0')
			f++;

		if (f == n)
		{
			for (int i = 1; i <= f; i += (k + 1))
				res++;

			cout << res << endl;
			continue;
		}
		else
		{
			for (int i = k + 1; i <= f; i += (k + 1))
				res++;
		}

		while (s[l] == '0')
			l--;

		for (int i = k + 1; i <= n - l - 1; i += (k + 1))
			res++;

		stack<int> S;
		for (int i = f; i <= l; i++)
		{
			if (s[i] == '1')
				S.push(i);
		}


		if (!S.empty())
		{
			int pos = S.top();
			while (1)
			{
				S.pop();
				if (S.empty())
					break;
				int len = pos - S.top();
				for (int i = k + 1; i < len - k; i += (k + 1))
					res++;
				pos = S.top();
			}

		}
		cout << res << endl;
	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1367/problem/C
 */
