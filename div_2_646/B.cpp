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
		string s;
		cin >> s;
		vector<int> count0(s.length(),0), count1(s.length(),0);

		if (s[0] == '0')
			count0[0]++;
		else
			count1[0]++;

		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '0')
				count0[i] = count0[i - 1] + 1;
			else
				count0[i] = count0[i - 1];
		}

		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '1')
				count1[i] = count1[i - 1] + 1;
			else
				count1[i] = count1[i - 1];
		}


		int res;

		if (count1[s.length() - 1] < count0[s.length() - 1])
			res = count1[s.length() - 1];
		else
			res = count0[s.length() - 1];

		for (int i = 0; i < s.length(); i++)
		{
			int d1, d2;
			//00000111111
			d1 = count1[i];
			d2 = count0[s.length() - 1] - count0[i];
			if (d1 + d2 < res)
				res = d1 + d2;
			//111111000000000
			d1 = count0[i];
			d2 = count1[s.length() - 1] - count1[i];
			if (d1 + d2 < res)
				res = d1 + d2;

		}

		cout << res << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1363/problem/B
 */
