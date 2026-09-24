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

	int t;
	cin >> t;
	while (t--)
	{
		vector<int> a;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		sort(a.begin(), a.end());

		for (int i = a.size() - 1; i > -1; i--)
			cout << a[i] << " ";

		cout << endl;

	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1312/problem/B
 */
