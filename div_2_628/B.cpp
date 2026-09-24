#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
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
		set<int> a;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.insert(ti);
		}

		cout << a.size() << endl;
	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1325/problem/B
 */
