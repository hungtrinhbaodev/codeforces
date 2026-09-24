#include<iostream>
#include<vector>
#define LL long long int
using namespace std;

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		LL n, m;
		LL sum = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			sum += ti;
		}

		if (sum < m)
			swap(sum, m);

		cout << m << endl;

	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1316/problem/A
 */
