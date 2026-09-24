#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define pi acos(-1)
#define LL long long int
#define module 1000000007
using namespace std;




int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int countOdd = 0, countWrong = 0, countEven = 0;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			if (ti % 2 == 0)
				countEven++;
			else
				countOdd++;
			if (ti % 2 != 0 && i % 2 == 0)
				countWrong++;
		}

		if (n % 2 == 0)
		{
			if (countEven != countOdd)
				cout << -1 << endl;
			else
			{
				cout << countWrong << endl;
			}
		}
		else
		{
			if (countEven - countOdd != 1)
				cout << -1 << endl;
			else
			{
				cout << countWrong << endl;
			}
		}

	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1367/problem/B
 */
