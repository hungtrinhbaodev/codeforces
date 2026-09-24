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

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		if (n == 1 || m == 1)
			cout << "YES" << endl;
		else
		{
			if (n == 2 && m == 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1345/problem/A
 */
