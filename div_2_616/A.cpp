#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

vector<int> res;
vector<int> a;


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
		int c1 = - 1, c2 = -1;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			char tc;
			cin >> tc;

			if (((int)tc - 48) % 2)
			{
				if (c1 == -1)
					c1 = (int)tc - 48;
				else
					c2 = (int)tc - 48;
			}
		}


		if (c1 != -1 && c2 != -1)
			cout << c1 << c2 << endl;
		else
			cout << -1 << endl;
	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1291/problem/A
 */
