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

	int n;
	vector<bool> used(10, false);
	string s;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			for (int j = 0; j < 10; j++)
			{
				if (!used[j])
				{
					used[j] = true;
					break;
				}
			}
		}
		else if (s[i] == 'R')
		{
			for (int j = 9; j > -1; j--)
			{
				if (!used[j])
				{
					used[j] = true;
					break;
				}
			}
		}
		else
		{
			int d = (int)(s[i] - 48);
			used[d] = false;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (used[i])
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1200/problem/A
 */
