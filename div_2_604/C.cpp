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

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		vector<int> a;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		int sum = n / 2;

		while (sum > 0 && a[sum] == a[sum - 1])
			sum--;

		if (sum == 0)
			cout << 0 << " " << 0 << " " << 0 << endl;
		else
		{
			bool ac = true;
			int  g = 0, s = 0, b = 0;
			int pos = 1, pos2 = -1;

			while (pos < sum && a[pos] == a[0])
				pos++;

			g = pos;

			pos += pos;
			pos2 = pos + 1;

			while (pos2 < sum && a[pos2] == a[pos])
				pos2++;

			s = pos2 - g;

			b = sum - g - s;

			if (b > g)
				cout << g << " " << s << " " << b << endl;
			else
				cout << 0 << " " << 0 << " " << 0 << endl;

		}

	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1265/problem/C
 */
