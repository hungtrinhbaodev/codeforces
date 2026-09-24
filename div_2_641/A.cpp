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
		LL n, k, d;
		cin >> n >> k;

		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				d = i;
				break;
			}
		}
		cout << n + d + (k - 1)*2 << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1350/problem/A
 */
