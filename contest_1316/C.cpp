#include<iostream>
#include<vector>
#define LL long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int n, m, p, a, b;
	cin >> n >> m >>p;
	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		if (ti % p != 0)
		{
			a = i;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		if (ti % p != 0)
		{
			b = i;
		}
	}

	cout << a + b << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1316/problem/C
 */
