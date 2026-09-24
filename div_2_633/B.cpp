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
		int n;
		vector<int> a, res;
		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		sort(a.begin(), a.end());

		for (int i = 0; i <= n / 2; i++)
		{
			res.push_back(a[n - 1 - i]);
			res.push_back(a[i]);
		}


		if (n % 2)
			res.pop_back();

		for (int i = n - 1; i > -1; i--)
			cout << res[i] << " ";

		cout << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1339/problem/B
 */
