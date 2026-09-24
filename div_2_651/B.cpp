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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, countOdd = 0, countEven = 0;
		cin >> n;
		vector<int> even, odd;
		for (int i = 0; i < 2 * n; i++)
		{
			int ti;
			cin >> ti;
			if (ti % 2 == 0)
			{
				countEven++;
				even.push_back(i + 1);
			}
			else
			{
				countOdd++;
				odd.push_back(i + 1);
			}

		}


		if (countOdd % 2 == 1)
		{
			even.pop_back(); odd.pop_back();
		}
		else
		{
			if (odd.size() >= 2)
			{
				odd.pop_back();
				odd.pop_back();
			}
			else
			{
				even.pop_back();
				even.pop_back();
			}
		}

		for (int i = 0; i < even.size() / 2; i++)
		{
			cout << even[i] << " " << even[even.size() - 1 - i] << endl;
		}
		for (int i = 0; i < odd.size() / 2; i++)
		{
			cout << odd[i] << " " << odd[odd.size() - 1 - i] << endl;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1370/problem/B
 */
