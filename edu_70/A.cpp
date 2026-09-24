#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
	int t;
	cin >> t;
	while (t--)
	{
		string s, t;
		cin >> s >> t;
		int pos1 = 0, pos2 = 0;

		for (int i = t.length() - 1; i > -1; i--)
		{
			if (t[i] == '1')
			{
				break;
			}
			else
				pos2++;
		}


		for (int i = s.length() - 1 - pos2; i > -1; i--)
		{
			if (s[i] == '1')
				break;
			else
				pos1++;
		}

		cout << pos1 << endl;
	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1202/problem/A
 */
