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
		LL n, k;
		cin >> n >> k;

		LL d = (k-1)*(k-1);
		//cout << n - d << endl;
		if (n - d <= 2 * k - 3 || n - d < 0)
			cout << "NO" << endl;
		else
		{
			if ((n - d) % 2 == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}

	}



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1327/problem/A
 */
