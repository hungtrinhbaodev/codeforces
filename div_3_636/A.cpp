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
		LL n;
		cin >> n;
		LL i = 3;
		while (i <= 2 * module)
		{
			if (n % i == 0)
			{
				cout << n / i << endl;
				break;
			}
			i = (i + 1) * 2 - 1;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1343/problem/A
 */
