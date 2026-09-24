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
	vector<int> b;
	vector<int> a;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		b.push_back(ti);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << a[n - 1] <<" "<< b[m - 1] << endl;
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1206/problem/A
 */
