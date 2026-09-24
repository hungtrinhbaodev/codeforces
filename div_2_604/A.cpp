#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
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
		string s, s1;
		cin >> s;
		
		bool ac = true;
		for (int i = 0; i < s.size() - 1 && ac; i++)
		{
			if (s[i] != '?')
			{
				if (s[i] == s[i + 1])
					ac = false;
			}
		}

		if (!ac)
			cout << -1 << endl;
		else
		{

			s1 = 'a' + s1;
			s1 = s1 + s;
			s1 = s1 + 'a';
	
			stack<int> c;

			for (int i = 0; i < s1.size(); i++)
			{
				if (s1[i] != '?')
					c.push(i);
			}

			while (true)
			{
				int j = c.top();
				c.pop();

				if (c.empty())
					break;

				char tc1, tc2;
				if (s1[j] == s1[c.top()])
				{
					if (s1[j] == 'a')
					{
						tc1 = 'b';
						tc2 = 'c';
					}
					else if (s1[j] == 'b')
					{
						tc1 = 'a';
						tc2 = 'c';
					}
					else
					{
						tc1 = 'a';
						tc2 = 'b';
					}
				}
				else
				{
					if (s1[j] != 'c' && s1[c.top()] != 'c')
					{
						tc1 = 'c';
						tc2 = s1[c.top()];
					}
					else if (s1[j] != 'b' && s1[c.top()] != 'b')
					{
						tc1 = 'b';
						tc2 = s1[c.top()];
					}
					else
					{
						tc1 = 'a';
						tc2 = s1[c.top()];
					}
				}

				for (int i = c.top() + 1; i < j; i++)
				{
					if ((i - c.top() - 1) % 2 == 0)
						s1[i] = tc1;
					else
						s1[i] = tc2;
				}

			}
			for (int i = 1; i < s1.length() - 1; i++)
				cout << s1[i];

			cout << endl;

		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1265/problem/A
 */
