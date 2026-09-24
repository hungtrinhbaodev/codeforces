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
		int n;
		cin >> n;
		vector<int> a(n,0);

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;

			ti += i;
			ti %= n;

			if (ti < 0)
				ti += n;

			a[ti]++;
		}

		bool ac = true;
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= 2)
				ac = false;
		}

		if (ac)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1345/problem/C
 */
