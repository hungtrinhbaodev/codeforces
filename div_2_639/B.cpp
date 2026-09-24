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
		int n, count = 0;
		cin >> n;
		while (n > 1)
		{
			for (int i = 1; i <= 2*sqrt(n); i++)
			{
				LL sum = (i) * (i + 1) / 2 * 3 - i;

				if (sum > n)
				{
					count++;
					n -=  (i - 1) * (i) / 2 * 3 - i + 1;
					break;
				}
				else if (sum == n)
				{
					count++;
					n -= sum;
					break;
				}
			}
		}
		//cout << n << endl;
		cout << count << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1345/problem/B
 */
