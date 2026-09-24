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

vector<string> t;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int count = 0;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '0')
				count++;
		}

		if (count == s.length())
		{
			for (int i = 0; i < 2 * s.length(); i++)
				cout << '0';
			cout << endl;
		}
		else if (count == 0)
		{
			for (int i = 0; i < 2 * s.length(); i++)
				cout << '1';
			cout << endl;
		}
		else
		{
			for (int i = 0; i < 2 * s.length(); i++)
			{
				if (i % 2 == 0)
					cout << '0';
				else
					cout << '1';
			}
			cout << endl;
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1342/problem/B
 */
