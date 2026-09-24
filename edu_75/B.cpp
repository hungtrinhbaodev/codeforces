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
		int n, countEvenWrong = 0, countOdd = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (s.length() % 2 == 1)
				countOdd++;
			else
			{
				int cnt0 = 0;
				for (int j = 0; j < s.length(); j++)
				{
					if (s[j] == '0')
						cnt0++;
				}
				if (cnt0 % 2 == 1)
					countEvenWrong++;
			}
		}

		if (countEvenWrong % 2 == 0)
			cout << n << endl;
		else
		{
			if (countOdd >= 1)
				cout << n << endl;
			else
				cout << n - 1 << endl;
		}

	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1251/problem/B
 */
