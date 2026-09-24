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
		string s, t;
		int n, pos1 = -1, pos2 = -1, count = 0;
		cin >> n >> s >> t;

		for (int i = 0; i < n; i++)
		{
			if (s[i] != t[i])
			{
				count++;
				if (pos1 == -1)
					pos1 = i;
				else
					pos2 = i;
			}
		}

		if (count == 2)
		{
			swap(s[pos1], t[pos2]);
			if (t == s)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (count == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1243/problem/B1
 */
