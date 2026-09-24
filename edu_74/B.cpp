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


	int t;
	cin >> t;
	while (t--)
	{
		set<int> hash;
		vector<int> a;
		int n, r;

		cin >> n >> r;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			hash.insert(ti);
		}

		set<int, int>::iterator it;
		for (it = hash.begin(); it != hash.end(); it++)
		{
			a.push_back(*it);
		}

		int m = a.size();
		int res = m;

		for (int i = m - 1; i > 0; i--)
		{
			//cout << a[i - 1] << " " << r * (m - i) << endl;
			if (a[i - 1] - r * (m - i) <= 0)
			{
				res = m - i;
				break;
			}
		}

		cout << res << endl;
	}
	
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1238/problem/B
 */
