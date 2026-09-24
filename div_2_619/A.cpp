#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#define LL long long int
#define module 998244353
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
		string a, b, c;
		cin >> a >> b >> c;

		bool ac = true;

		for (int i = 0; i < a.size(); i++)
		{

			if (a[i] != c[i] && b[i] != c[i])
				ac = false;
		}
		
		if (ac)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1301/problem/A
 */
