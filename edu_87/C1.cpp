#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define pi acos(-1)
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
		float n;
		cin >> n;
		n *= 2;
		printf("%0.6f\n", tan((pi - 2 * pi / n) / 2));
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1354/problem/C1
 */
