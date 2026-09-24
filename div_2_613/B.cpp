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

	int t;
	cin >> t;
	while (t--)
	{
		vector<LL> a, pos, res;
		int n;
		LL sum = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			sum += ti;
			a.push_back(ti);
			res.push_back(0);
			pos.push_back(0);
		}

		res[0] = a[0];
		pos[0] = 0;

		for (int i = 1; i < n; i++)
		{
			if (a[i] + res[i - 1] > 0 && res[i - 1] > 0)
			{
				res[i] = res[i - 1] + a[i];
				pos[i] = pos[i - 1];
			}
			else
			{
				res[i] = a[i];
				pos[i] = i;
			}
		}
		/*
		for (int i = 0; i < n; i++)
			cout << res[i] << " " << pos[i] << endl;
		*/
		bool ac = false;
		for (int i = 0; i < n && !ac; i++)
		{
			if (res[i] >= sum && i - pos[i] + 1 < n)
				ac = true;
		}

		if (ac)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1285/problem/B
 */
