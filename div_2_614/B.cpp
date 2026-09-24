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

	LL n;
	double res = 0;
	cin >> n;

	while (n > 0)
	{
		res += (double)1 / n;
		n--;
	}

	printf("%0.6f\n", res);
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1293/problem/B
 */
