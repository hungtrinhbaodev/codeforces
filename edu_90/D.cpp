#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define MAXSIZE 101
#define MAXSUM 1002
#define pi acos(-1)
#define LL long long int
#define module 1000000007
using namespace std;




int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<LL> a, b, dp, c;
		int n;
		LL sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin>> ti;
			if (i % 2 == 0)
				sum += ti;
			a.push_back(ti);
		}
	//	a.push_back(0);
	//	a.push_back(0);
	//	n += 2;



		if (n % 2 == 1)
		{
			a.push_back(0);
			n++;
		}

		for (int i = 0; i < n / 2; i++)
		{
			b.push_back(a[2 * i + 1] - a[2 * i]);
		}

		for (int i = 0; i < n / 2 - 1; i++)
		{
			c.push_back(a[2 * i + 1] - a[2 * i + 2]);
		}

		if (b[0] <= 0)
			dp.push_back(0);
		else
			dp.push_back(b[0]);



		for (int i = 1; i < n / 2; i++)
		{
			if (dp[i - 1] + b[i] >= 0)
				dp.push_back(dp[i - 1] + b[i]);
			else
				dp.push_back(0);
		}

		LL max = 0;
		for (int i = 0; i < n / 2; i++)
		{
			if (dp[i] > max)
				max = dp[i];
		}

		dp.clear();
		if (c.empty() || c[0] <=0)
			dp.push_back(0);
		else
			dp.push_back(c[0]);


		for (int i = 1; i < n / 2 - 1; i++)
		{
			if (dp[i - 1] + c[i] >= 0)
				dp.push_back(dp[i - 1] + c[i]);
			else
				dp.push_back(0);
		}

		for (int i = 0; i < n / 2 - 1; i++)
		{
			if (dp[i] > max)
				max = dp[i];
		}
		//cout << max << endl;
		cout << sum + max << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1373/problem/D
 */
