#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

int gcd(LL a, LL b) {
	LL tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	LL n;
	cin >> n;
	
	LL res = n;

	for(int i = 2 ; i<=sqrt(n); i++)
	{
		if (n % i == 0)
		{
			LL j = n / i;
			if (gcd(i, j) == 1)
			{
				LL d;
				if (i > j)
					d = i;
				else
					d = j;

				if (d < res)
					res = d;
			}

		}
	}

	cout << n / res << " " << res << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1285/problem/C
 */
