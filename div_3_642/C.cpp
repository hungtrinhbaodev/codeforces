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
		LL n;
		cin >> n;

		LL res = 0;
		for (LL i = 1; i <= n / 2; i++)
		{
			LL d = 2 * i + 1, d1 = 2*(i-1)+1;
			d = d * d, d1 = d1 * d1;
			d -= d1;
			//cout << d * (i) << endl;
			res += d * (i);
		}

		cout << res << endl;
	}
	

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1353/problem/C
 */
