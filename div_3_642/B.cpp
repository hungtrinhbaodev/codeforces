#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
	
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		vector<int> a, b, c;
		cin >> n >> k;

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

		sort(a.begin(),a.end());
		sort(b.begin(), b.end());


		for (int i = 0; i < k; i++)
		{
			c.push_back(a[i]);
			c.push_back(b[n - 1 - i]);
		}

		sort(c.begin(), c.end());

		LL sum = 0;

		for (int i = 0; i < k; i++)
			sum += c[2*k - 1 - i];

		for (int i = k; i < n; i++)
			sum += a[i];

		cout << sum << endl;
	}
	

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1353/problem/B
 */
