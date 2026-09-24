#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

pair<LL,LL> Compare(vector<LL> &a, int l, int r,int i)
{
	if (i == -1)
	{
		return make_pair(0, 0);
	}

	LL d = 1;
	pair<LL, LL> x, y;
	d <<= i;

	if (a[l] & d)
	{
		x = Compare(a, l, r, i - 1);
		return make_pair(x.first, d + x.second);
	}


	if (!(a[r] & d))
	{
		x = Compare(a, l, r, i - 1);
		return make_pair(x.first, x.second);
	}

	int pos = l;

	while (!(a[pos] & d))
			pos++;

	x = Compare(a, l, pos - 1, i - 1);
	y = Compare(a, pos, r, i - 1);
	
	if (x.first < y.first)
		return make_pair(d + x.first, x.second);
	else
		return make_pair(d + y.first, d + y.second);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	vector<LL> a;
	cin >> n;

	for (int i = 0; i < n; i++)
	{ 
		LL ti;
		cin >> ti;
		a.push_back(ti);
	}

	sort(a.begin(), a.end());

	cout << Compare(a, 0, n - 1, 30).first << endl;



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1285/problem/D
 */
