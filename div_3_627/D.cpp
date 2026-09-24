#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long int
#define module 998244353
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> a, b;
	LL res = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
	}

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		b.push_back(ti);
	}

	for (int i = 0; i < n; i++)
		a[i] = a[i] - b[i];

	sort(a.begin(), a.end());

	/*
	vector<int>::iterator low = lower_bound(a.begin() + 3, a.end(), 0);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;
	
	cout << low - a.begin() << endl;
	*/

	for (int i = 0; i < n - 1; i++)
	{
		int ti = 0;
		if (a[i] < 0)
			ti = -a[i];

		vector<int>::iterator low = upper_bound(a.begin() + i + 1, a.end(), ti);
		int pos = low - a.begin();
		//cout << i << " " << pos << endl;
		res += n - pos;
	}

	cout << res << endl;


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1324/problem/D
 */
