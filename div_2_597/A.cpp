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

int gcd(int a, int b) {
	int tmp;
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

	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		if (gcd(a, b) != 1)
			cout << "Infinite" << endl;
		else
			cout << "Finite" << endl;
	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1245/problem/A
 */
