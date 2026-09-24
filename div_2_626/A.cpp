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
		vector<int> a;
		cin >> n;

		bool hasEven = false;
		int pos = -1;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			if (ti % 2 == 0)
			{
				hasEven = true;
				pos = i;
			}
				
		}

		if (hasEven)
			cout << 1 << endl << pos + 1 << endl;
		else
		{
			if (n >= 2)
				cout << 2 << endl << 1 << " " << 2 << endl;
			else
				cout << -1 << endl;
		}




	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1323/problem/A
 */
