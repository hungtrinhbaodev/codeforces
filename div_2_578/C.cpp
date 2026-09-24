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

LL UCLN(LL a, LL b)
{
	LL tmp;
	while (b != 0)
	{
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

	LL x, y, q, ucln;

	cin >> x >> y >> q;


	ucln = UCLN(x, y);
	LL cx = x / ucln;
	LL cy = y / ucln;


	while (q--)
	{
		int sx, sy;
		LL ex, ey, dx, dy;

		cin >> sx >> ex >> sy >> ey;

		if (sx == 1)
			dx = (ex - 1) / cx;
		else
			dx = (ex - 1) / cy;

		if (sy == 1)
			dy = (ey - 1) / cx;
		else
			dy = (ey - 1) / cy;


		if (dy == dx)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1200/problem/C
 */
