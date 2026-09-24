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

	int n, sum0 = 0, sum1 = 0;
	vector<int> a;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
		if (ti != 0 && ti % 2 == 0)
			sum0++;
		else if (ti != 0 && ti % 1 == 0)
			sum1++;
	}

	if (n % 2 == 0)
	{
		sum0 = n / 2 - sum0;
		sum1 = n / 2 - sum1;
	}
	else
	{
		sum0 = n / 2 - sum0;
		sum1 = n / 2 + 1 - sum1;
	}

	int pos = 0, k , m;
	pair<int, int> l, f;

	while (pos < n && a[pos] == 0)
		pos++;

	k = pos;
	if (pos == n)
	{
		if (n != 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}

	if (a[pos] % 2 == 0)
		f = make_pair(pos, 0);
	else
		f = make_pair(pos, 1);

	pos = n - 1;
	while (a[pos] == 0)
		pos--;

	m = pos;
	if (a[pos] % 2 == 0)
		l = make_pair(n - 1 -pos, 0);
	else
		l = make_pair(n - 1 - pos, 1);


	vector<int>  c1, c0;
	int res = 0;
	for (int i = k; i < m; i++)
	{
		if (a[i] != 0 && a[i  + 1] != 0)
		{
			if (a[i] % 2 != a[i + 1] % 2)
				res++;
		}
		else
		{
			int pre, last;
			pre = a[i];

			int j = i + 1;

			while (a[j] == 0)
				j++;

			last = a[j];

			if (a[i] % 2 != a[j] % 2)
			{
				res++;
			}
			else
			{
				if (a[i] % 2 == 0)
					c0.push_back(j - i - 1);
				else
					c1.push_back(j - i - 1);
			}

			i = j - 1;
		}
	}
	
	sort(c0.begin(), c0.end());
	sort(c1.begin(), c1.end());

	int j = 0, res0 = 0, res1 = 0;
	while (j < c0.size() && sum0 > 0)
	{
		res0++;
		sum0 -= c0[j];
		j++;
	}

	if (sum0 < 0)
	{
		sum0 += c0[j - 1];
		res0--;
	}
	
	j = 0;
	while (j < c1.size() && sum1 > 0)
	{
		res1++;
		sum1 -= c1[j];
		j++;
	}

	if (sum1 < 0)
	{
		sum1 += c1[j - 1];
		res1--;
	}
	
	res += 2*(c0.size() - res0 + c1.size() - res1);
	
	if (f.first > l.first)
		swap(f, l);

	//cout << sum0 << " " << sum1 << endl;
	//cout << l.first << " " << f.first << endl;
	if (f.second == l.second)
	{
		if (f.second == 0)
		{
			if (sum0 - f.first >= 0)
			{
				sum0 -= f.first;
				if (sum0 - l.first < 0)
					res += 1;
			}
			else
				res += 2;
		}
		else
		{
			if (sum1 - f.first >= 0)
			{
				sum1 -= f.first;
				if (sum1 - l.first < 0)
					res += 1;
			}
			else
				res += 2;
		}
	}
	else
	{
		if (f.second == 0)
		{
			if (sum0 - f.first >= 0)
			{
				if (sum1 - l.first < 0)
					res += 1;
			}
			else
			{
				if (sum1 - l.first < 0)
					res += 2;
				else
					res += 1;
			}
		}
		else
		{
			if (sum1 - f.first >= 0)
			{
				if (sum0 - l.first < 0)
					res += 1;
			}
			else
			{
				if (sum0 - l.first < 0)
					res += 2;
				else
					res += 1;
			}
		}
	}

	cout << res << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1287/problem/C
 */
