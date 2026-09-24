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

	int n;
	int a[3][3];
	cin >> n;

	LL d = 1, t = 1;

	while (d <= n)
	{
		d <<= 1;
		t <<= 1;
		t |= 1;
	}
		
	a[0][0] = t;
	a[0][1] = n;
	a[1][0] = d;
	
	a[1][1] = t;
	a[0][2] = 0;
	a[2][0] = 0;

	a[1][2] = t;
	a[2][1] = t;
	a[2][2] = t >> 1;

	cout << 3 << " " << 3 << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << " ";

		cout << endl;
	}

	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1332/problem/D
 */
