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

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n;
		cin >> s;

		int f = -1, l =  -1, j = 0;
		while (j < n && s[j] == '0')
			j++;

		if (j == n)
		{
			cout << n << endl;
			continue;
		}

		f = j;

		j = n - 1;
		while (j > -1 && s[j] == '0')
			j--;

		l = j;

		if (n - f > l + 1)
			cout << 2 * (n - f) << endl;
		else
			cout << 2 * (l + 1) << endl;

	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1244/problem/B
 */
