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
	
	LL n;

	cin >> n;

	n *= 2;

	LL d = (n + 1) * (n) / 2;

	if (d % 2 == 0)
		cout << "NO" << endl;
	else
	{
		vector<int> even, odd, res1,res2;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
				even.push_back(i);
			else
				odd.push_back(i);
		}

		for (int i = 1; i <= n / 2; i++)
		{
			if (i % 2 == 1)
			{
				res1.push_back(odd[i - 1]);
				res2.push_back(even[i - 1]);
			}
			else
			{
				res1.push_back(even[i - 1]);
				res2.push_back(odd[i - 1]);
			}
		}

		cout << "YES" << endl;

		for (int i = 0; i < n / 2; i++)
			cout << res1[i] << " ";

		for (int i = 0; i < n / 2; i++)
			cout << res2[i] << " ";
		cout << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1206/problem/C
 */
