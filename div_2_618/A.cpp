#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
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
		int n, res = 0, sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			if (ti == 0)
			{
				sum += 1;
				res++;
			}
			else
				sum += ti;
		}

		if (sum == 0)
			cout << res + 1 << endl;
		else
			cout << res << endl;

	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1300/problem/A
 */
