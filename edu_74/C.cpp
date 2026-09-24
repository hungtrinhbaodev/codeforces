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
		int h, n;
		vector<int> a;
		cin >> h >> n;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}
		a.push_back(0);

		int res = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] - a[i + 1] == 1)
			{
				i++;
			}
			else
				res++;
		}

		cout << res << endl;
	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1238/problem/C
 */
