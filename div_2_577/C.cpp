#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
	


	LL n, k;
	vector<LL> a;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
	}

	sort(a.begin(), a.end());
	
	int j = 1;
	for (int i = n / 2; i < n - 1; i++)
	{
		if ((a[i + 1] - a[i]) * j <= k)
		{
			k -= (a[i + 1] - a[i]) * j;
		}
		else
		{
			cout << a[i] + k / j << endl;
			return 0;
		}
		j++;
	}
	
	cout << a[n - 1] + k / j << endl;
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1201/problem/C
 */
