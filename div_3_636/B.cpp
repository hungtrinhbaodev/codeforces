#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
		cin >> n;
		if ((n / 2) % 2 == 1)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			LL sum = 0;
			for (LL i = 0; i < n / 2; i++)
			{
				cout << 2 * i + 2 << " ";
				sum += 2 * i + 2;
			}
			for (LL i = 0; i < n / 2; i++)
			{
				if (i != n / 2 - 1)
				{
					cout << 2 * i + 1 << " ";
					sum -= 2 * i + 1;
				}
				else
				{
					cout << sum << endl;
				}
		
			}
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1343/problem/B
 */
