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

	LL n, l, r;

	cin >> n >> l >> r;

	LL min = 0, max = 0, i = 1, d = 1;

	while (i <= l)
	{
		min += d;
		d <<= 1;
		i++;
	}


	min += (n - l);


	i = 1;
	d = 1;

	while (i <= r)
	{
		max += d;
		d <<= 1;
		i++;
	}

	d >>= 1;
	max += (n - r) * d;

	cout << min << " " << max << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1204/problem/B
 */
