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

	int n, m, k, x, y;
	cin >> n >> m >> k;

	for (int i = 0; i < 2 * k; i++)
		cin >> x >> y;

	cout << n * m + n + m  - 3<< endl;
	for (int i = 0; i < n - 1; i++)
		cout << 'U';

	for (int i = 0; i < m - 1; i++)
		cout << 'L';

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <n - 1; j++)
		{
			if (i % 2 == 0)
				cout << 'D';
			else
				cout << 'U';
		}
		if(i < m - 1)
			cout << 'R';
	}

	cout << endl;



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1327/problem/C
 */
