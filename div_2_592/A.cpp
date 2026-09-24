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
	while(t--)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;

		int resa, resb;
		if (a % c == 0)
			resa = a / c;
		else
			resa = a / c + 1;

		if (b % d == 0)
			resb = b / d;
		else
			resb = b / d + 1;

		if (resa + resb <= k)
			cout << resa << " " << resb << endl;
		else
			cout << -1 << endl;
	}
	
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1244/problem/A
 */
