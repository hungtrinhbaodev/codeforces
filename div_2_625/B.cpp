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
	
	LL a[800007];
	int n;

	cin >> n;

	for (int i = 0; i <800007; i++)
		a[i] = 0;

	for (int i = 0; i < n; i++)
	{
		LL ti;
		cin >> ti;

		a[ti - i + 400000] += ti;
	}

	LL max = a[0];

	for (int i = 1; i < 800007; i++)
		if (max < a[i])
			max = a[i];

	cout << max << endl;



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1321/problem/B
 */
