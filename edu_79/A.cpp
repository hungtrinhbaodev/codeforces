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
		LL r, g, b;
		cin >> r >> g >> b;

		if (r < g)
			swap(r, g);

		if (r < b)
			swap(r, b);

		if (b + g >= r - 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1279/problem/A
 */
