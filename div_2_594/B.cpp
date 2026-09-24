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
	LL h = 0, v = 0;
	for (int i = 0; i < n / 2; i++)
		h += a[i];
	for (int i = n / 2; i < n; i++)
		v += a[i];

	cout << h * h + v * v << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1248/problem/B
 */
