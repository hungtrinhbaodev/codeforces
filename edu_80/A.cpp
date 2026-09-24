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
		LL d, n;
		cin >> n >> d;
		bool ac = false;
		for (LL i = 0; i <= sqrt(d) && !ac; i++)
		{
			LL k;
			if (d % (i + 1) == 0)
				k = d / (i + 1);
			else
				k = d / (i + 1) + 1;

			if (i + k <= n)
				ac = true;
		}

		if (ac)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1288/problem/A
 */
