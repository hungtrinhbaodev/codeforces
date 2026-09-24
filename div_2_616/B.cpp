#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

vector<int> res;
vector<int> a;


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
		vector<bool> l, r;
		l.push_back(1);
		r.push_back(1);

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		for (int i = 1; i < n; i++)
		{
			if (a[i] - i >= 0 && l[i - 1])
				l.push_back(1);
			else
				l.push_back(0);

			if (a[n - 1 - i] >= i && r[i - 1])
				r.push_back(1);
			else
				r.push_back(0);

		}

		for (int i = 0; i < n / 2; i++)
			swap(r[i], r[n - 1 - i]);

		bool ac = false;


		for (int i = 0; i < n && !ac; i++)
		{
			if (l[i] && r[i])
				ac = true;
		}

		if (ac)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1291/problem/B
 */
