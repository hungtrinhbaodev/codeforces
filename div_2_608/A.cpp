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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int m1, m2;

	if (a > d)
		m1 = d;
	else
		m1 = a;


	if (b > c)
		m2 = c;
	else
		m2 = b;

	if (m2 > d)
		m2 = d;


	if (e > f)
	{
		if (d - m1 < m2)
			cout << m1 * e + (d - m1) * f << endl;
		else
			cout << m1 * e + m2 * f << endl;
	}
	else
	{
		if (d - m2 < m1)
			cout << m2 * f + (d - m2) * e << endl;
		else
			cout << m2 * f + m1 * e << endl;
	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1271/problem/A
 */
