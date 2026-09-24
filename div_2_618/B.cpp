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
		int n;
		vector<int> a;
		cin >> n;

		for (int i = 0; i <2*n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}

		sort(a.begin(), a.end());

		cout << a[n] - a[n - 1] << endl;

	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1300/problem/B
 */
