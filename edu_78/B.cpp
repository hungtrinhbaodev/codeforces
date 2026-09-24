#include<iostream>
#include<vector>
#include<algorithm>
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
		LL a, b;
		cin >> a >> b;

		if (a > b)
			swap(a, b);

		LL k = 2*(b - a), res = -1;

		for (LL i = 0; i <= sqrt(10000000007); i++)
		{
			if (i * (i + 1) / 2 + (a + b) >= 2 * b && (i*(i+1)/2 + (a+b)) % 2 == 0)
			{
				res = i;
				break;
			}
		}

		cout << res << endl;
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1278/problem/B
 */
