#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<map>
#define LL long long int
#define module 1000000007
using namespace std;

vector<string> t;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		LL a, b, x, y;
		cin >> x >> y >> a >> b;

		if (x > y)
			swap(x, y);

		if (a * 2 < b)
		{
			cout << (x + y) * a << endl;
		}
		else
			cout << (y - x) * a + x * b << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1342/problem/A
 */
