#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define pi acos(-1)
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
		int n;
		cin >> n;
		vector<int> a;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		sort(a.begin(), a.end());
		int res = 0;
		int sum = 1;
		for (int i = 0; i < a.size(); i++)
		{
			if (sum  >= a[i])
			{
				res = i + 1;
			}
			sum++;
		}

		cout << res + 1 << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1358/problem/B
 */
