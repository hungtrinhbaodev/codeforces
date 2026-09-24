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

vector<string> t;

LL UCLN(LL a, LL b) {
	LL tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

LL BCNN(LL a, LL b)
{
	return a * b / UCLN(a, b);
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
		int q;
		LL a, b, l, r;

		cin >> a >> b >> q;

		if (a < b)
			swap(a, b);

		LL bcnn = BCNN(a, b);
		vector<LL> res;

		while (q--)
		{
			cin >> l >> r;

			LL cl, cr;

			l--;

			cl = (l / bcnn) * a;

			if (l - (l / bcnn) * bcnn + 1 > a)
				cl += a;
			else
				cl += l - (l / bcnn) * bcnn + 1;


			cr = (r / bcnn) * a;

			if ((r - (r / bcnn) * bcnn + 1 > a))
				cr += a;
			else
				cr += r - (r / bcnn) * bcnn + 1;

			//cout << cl << " " << cr << endl;
			res.push_back((r - l) - (cr - cl));

		}

		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1342/problem/C
 */
