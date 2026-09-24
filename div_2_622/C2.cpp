#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#define LL long long int
#define module 998244353
using namespace std;


vector<LL> a, dpLeft, dpRight;
int n;

void solve(vector<LL> & b)
{
	b.push_back(a[0]);
	stack<pair<LL, LL>> s;
	s.push(make_pair(a[0], 0));

	for (int i = 1; i < n; i++)
	{
		while (!s.empty() && s.top().first > a[i] )
			s.pop();

		if (s.empty())
			b.push_back(a[i] * (i + 1));
		else
			b.push_back(b[s.top().second] + a[i] * (i - s.top().second));

		s.push(make_pair(a[i], i));
	}
}

void inv(vector<LL>& a)
{
	for (int i = 0; i < a.size() / 2; i++)
	{
		swap(a[i], a[a.size() - 1 - i]);
	}
}


void show()
{

	LL max = -1, pos = 0;
	for (int i = 0; i < dpLeft.size(); i++)
	{
	
		if (dpLeft[i] + dpRight[i] - a[i] > max)
		{
			max = dpLeft[i] + dpRight[i] - a[i];
			pos = i;
		}
	}

	vector<int> res(n, 0);
	res[pos] = a[pos];
	max = a[pos];
	for (int i = pos - 1; i > -1; i--)
	{
		if (a[i] < max)
		{
			max = a[i];
		}

		res[i] = max;
	}

	max = a[pos];
	for (int i = pos + 1; i < n; i++)
	{
		if (a[i] < max)
		{
			max = a[i];
		}

		res[i] = max;
	}


	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		LL ti;
		cin >> ti;
		a.push_back(ti);
	}

	solve(dpLeft);
	inv(a);
	solve(dpRight);
	inv(dpRight);
	inv(a);

	show();

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1313/problem/C2
 */
