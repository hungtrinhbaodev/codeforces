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
		vector<int> hash(s.length() + 7, -1);
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '+')
				sum++;
			else
				sum--;

			if (sum < 0 && hash[-sum] == -1)
			{
				hash[-sum] = i + 1;
			}
		}

		int n = s.length() + 6;
		while (n>=0 && hash[n] == -1)
			n--;

		if (n <= 0)
			cout << s.length() << endl;
		else
		{
			LL res = s.length();
			for (int i = 0; i < n; i++)
			{
				res += hash[i + 1];
			}

			cout << res << endl;
		}
	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1373/problem/C
 */
