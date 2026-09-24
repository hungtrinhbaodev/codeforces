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


	int n, m;
	cin >> n >> m;

	int res = -1;
	for (int i = n; i <= m; i++)
	{
		bool ac = true;
		vector<int> digit(10, 0);
		int k = i;
		while (k > 0)
		{
			digit[k % 10]++;
			k /= 10;
		}

		for (int j = 0; j < 10; j++)
		{
			if (digit[j] > 1)
				ac = false;
		}

		if (ac)
		{
			res = i;
			break;
		}
	}

	cout << res << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1228/problem/A
 */
