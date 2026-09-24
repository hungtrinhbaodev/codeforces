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
		string s;
		cin >> n;

		if (n % 2 == 0)
		{
			for (int i = 0; i < n / 2; i++)
				cout << 1;

			cout << endl;
		}
		else
		{
			cout << 7;
			for (int i = 0; i < n / 2 - 1; i++)
				cout << 1;
			cout << endl;
		}

	}



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1295/problem/A
 */
