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
		int n, m;
		LL countOdd1 = 0, countEven1 = 0, countOdd2 = 0, countEven2 = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			if (ti % 2 == 0)
				countEven1++;
			else
				countOdd1++;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int ti;
			cin >> ti;
			if (ti % 2 == 0)
				countEven2++;
			else
				countOdd2++;
		}
		cout << countOdd1 * countOdd2 + countEven1 * countEven2 << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1248/problem/A
 */
