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


	int t;
	cin >> t;
	while (t--)
	{
		vector<bool> lets(26, 0);
		stack<int> Si;
		stack<char> Sc;
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++)
		{
			if (Sc.empty())
			{
				Sc.push(s[i]);
				Si.push(1);
			}
			else
			{
				if (s[i] == Sc.top())
				{
					int t = Si.top();
					Si.pop();
					t++;
					Si.push(t);
				}
				else
				{
					char tc = Sc.top();
					int t = Si.top();
					if (t % 2 == 1)
					{
						lets[tc - 97] = true;
					}
					Sc.push(s[i]);
					Si.push(1);
				}
			}
		}

		if (!Sc.empty())
		{
			char tc = Sc.top();
			int t = Si.top();
			if (t % 2 == 1)
			{
				lets[tc - 97] = true;
			}
		}
			
		for (int i = 0; i < 26; i++)
		{
			if (lets[i])
				cout << (char)(i + 97);
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1251/problem/A
 */
