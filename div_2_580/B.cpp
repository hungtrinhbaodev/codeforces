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

	int n;
	LL res = 0;
	int count0 = 0, count_1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;

		if (ti > 0)
		{
			res += ti - 1;
		}
		else if (ti == 0)
		{
			count0++;
		}
		else
		{
			res += -1 - ti;
			count_1++;
		}
	}

	if (count_1 % 2 == 0)
		cout << res + count0<< endl;
	else
	{
		if (count0 > 0)
			cout << res + count0 << endl;
		else
			cout << res + 2 << endl;
	}
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1206/problem/B
 */
