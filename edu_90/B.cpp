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
		int count = 0;
		string s;
		stack<char> st;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (st.empty())
				st.push(s[i]);
			else
			{
				if (st.top() != s[i])
				{
					st.pop();
					count++;
				}
				else
					st.push(s[i]);
			}
		}

		if (count % 2 == 1)
			cout << "DA" << endl;
		else
			cout << "NET" << endl;
	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1373/problem/B
 */
