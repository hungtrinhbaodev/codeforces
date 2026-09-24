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
		LL n, k;
		cin >> n >> k;
		k--;

		for (int i = 0; i < k; i++)
		{
			LL d = n;
			int maxd = -1, mind = 10;

			while (d > 0)
			{
				int k = d % 10;
				if (maxd < k)
					maxd = k;
				if (mind > k)
					mind = k;
				d /= 10;
			}

			n += mind * maxd;

			if (mind == 0)
				break;
		}

		cout << n << endl;
	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1355/problem/A
 */
