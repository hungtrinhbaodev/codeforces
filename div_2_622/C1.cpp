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

	vector<int> a, res;
	int n;
	LL maxRes = -1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
		res.push_back(ti);
	}

	for (int i = 0; i < n; i++)
	{
		LL maxhigh = a[i];
		vector<int> tv(n, 0);
		LL tsum = a[i];
		tv[i] = a[i];
		for (int j = i - 1; j > -1; j--)
		{
			if (a[j] < maxhigh)
				maxhigh = a[j];

			tsum += maxhigh;
			tv[j] = maxhigh;
		}
		maxhigh = a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < maxhigh)
				maxhigh = a[j];

			tsum += maxhigh;
			tv[j] = maxhigh;
		}

		if (tsum > maxRes)
		{
			maxRes = tsum;
			res = tv;
		}

	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";

	cout << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1313/problem/C1
 */
