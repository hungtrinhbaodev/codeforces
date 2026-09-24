#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#include<map>
#define LL long long int
#define module 1000000007
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s,v;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back('0');
	}

	int i = s.length() - 1;
	int res = 0;
	while (i > -1)
	{
		v[i] = '1';
		if (v < s)
			res++;
		v[i] = '0';
		i -= 2;
	}
	cout << res << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1204/problem/A
 */
