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
		string s, res;
		cin >> s;
		res.push_back(s[0]);
		for (int i = 1; i < s.length() - 1; i += 2)
			res.push_back(s[i]);
		res.push_back(s[s.length() - 1]);
		cout << res << endl;
	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1367/problem/A
 */
