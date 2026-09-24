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
		int n, countf = 0, countl = 0;
		cin >> n;
		string s, res;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
				break;
			else
				countf++;
		}

		for (int i = n - 1; i > -1; i--)
		{
			if (s[i] == '0')
				break;
			else
				countl++;
		}

		if (countf + countl >= n)
		{
			cout << s << endl;
			continue;
		}

		while (countf--)
			res.push_back('0');
		res.push_back('0');
		while (countl--)
			res.push_back('1');
		cout << res << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1369/problem/B
 */
