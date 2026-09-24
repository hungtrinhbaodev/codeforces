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
		LL a, b;
		cin >> a >> b;
		if (a - b <= 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1238/problem/A
 */
