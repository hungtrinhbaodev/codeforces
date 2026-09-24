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

	int n;
	string s;
	cin >> n >> s;

	for (char i = 'z'; i > 'a'; i--)
	{
		// Xoa tu z ve b
		bool ac = true;
		while (ac)
		{
			int count = 0;
			for (int j = 0; j < s.length(); j++)
			{
				if (j != 0 && j != s.length() - 1)
				{
					if (s[j] == i)
					{
						if (s[j - 1] == i - 1 || s[j + 1] == i - 1)
						{
							s.erase(s.begin() + j);
							j--;
							count++;
						}
					}
				}
				else
				{
					if (j == 0)
					{
						if (s[j] == i && s[j + 1] == i - 1)
						{
							s.erase(s.begin() + j);
							j--;
							count++;
						}
					}
					else
					{
						if (s[j] == i && s[j - 1] == i - 1)
						{
							s.erase(s.begin() + j);
							j--;
							count++;
						}
					}
				}
			}
			if (count == 0)
				ac = false;
		}
	}

	cout << n - s.length() << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1321/problem/C
 */
