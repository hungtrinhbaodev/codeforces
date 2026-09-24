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
		int n;
		string s;
		cin >> n >> s;

		int moment = 0;

		while (true)
		{
			bool Update = false;
			string tv = s;
			for (int i = 0; i < n - 1; i++)
			{
				if (s[i] == 'A' && s[i + 1] == 'P')
				{
					tv[i + 1] = 'A';
					Update = true;
				}
			}

			if (!Update)
				break;
			else
			{
				s = tv;
				moment++;
			}
		}

		cout << moment << endl;

	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1287/problem/A
 */
