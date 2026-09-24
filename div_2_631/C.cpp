#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<int> a;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
	}

	bool ac = true;

	for (int i = 0; i < m; i++)
	{
		if (n - a[i] < i)
			ac = false;
	}

	if (!ac)
		cout << -1 << endl;
	else
	{
		vector<int> res;
		for (int i = m - 1; i > -1; i--)
		{
			if (n - a[i] < i)
			{
				res.push_back(i + 1);
				n = i;
			}
			else
			{
				n -= a[i];
				res.push_back(n + 1);
			}
		}

		if (n > 0)
			cout << -1 << endl;
		else
		{
			for (int i = m - 1; i > -1; i--)
				cout << res[i] << " ";

			cout << endl;
		}

	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1330/problem/C
 */
