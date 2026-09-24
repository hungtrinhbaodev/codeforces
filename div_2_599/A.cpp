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

		int pos = 1;
		for (int i = 2; i <= n; i++)
		{
			if (a[n - i] >= i)
				pos = i;
			else
				break;
		}

		cout << pos << endl;

	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1243/problem/A
 */
