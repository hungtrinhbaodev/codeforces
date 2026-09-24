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
		LL A, B;
		cin >> A >> B;

		LL k = 9, count = 0;
		while (B >= k)
		{
			count++;
			k = k * 10 + 9;
		}

		cout << A * count << endl;
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1288/problem/B
 */
