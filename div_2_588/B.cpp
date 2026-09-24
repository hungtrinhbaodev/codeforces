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

	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (count == m)
			break;


		if (i == 0)
		{
			if (s[i] != '1')
			{
				s[i] = '1';
				count++;
			}

		}
		else
		{
			if (s[i] != '0')
			{
				s[i] = '0';
				count++;
			}
		}

	}

	if (s.length() == 1 && m >= 1)
		cout << 0 << endl;
	else
		cout << s << endl;


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1230/problem/B
 */
