#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;


bool SS(pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> a;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(make_pair(ti, i));
	}

	sort(a.begin(), a.end(), SS);

	int res = 0;

	for (int i = 0; i < n; i++)
	{
		res += a[i].first * i + 1;
	}

	cout << res << endl;

	for (int i = 0; i < n; i++)
		cout << a[i].second + 1 << " ";

	cout << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1216/problem/B
 */
