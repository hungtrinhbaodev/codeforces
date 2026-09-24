#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long int
#define module 998244353
using namespace std;

bool check(int mid, vector<int> a)
{
	bool ac = true;
	int pos = 0;

	while (pos + mid < a.size() && ac)
	{
		if (a[pos] != a[pos + mid])
		{
			pos = a[pos + mid];
		}
		else
			ac = false;
	}

	return ac;
}

int binarySearch(int l, int r, vector<int> a)
{
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		bool ac = check(mid, a);
		if (ac)
			r = mid;
		else
			l = mid;

	}
	return r;
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
		string s;
		cin >> s;
		vector<int> a;
		a.push_back(0);
		for (int i = 1; i <= s.size(); i++)
		{
			if (s[i - 1] != 'R')
				a.push_back(a[i - 1]);
			else
				a.push_back(i);
		}

		cout << binarySearch(0, s.size() + 1, a)<<endl;

	}

//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1324/problem/C
 */
