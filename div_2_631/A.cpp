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
		int n, x;
		vector<int> a(200,0);
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			
			a[ti - 1] = 1;
		}


		int count = 0, res = 1;
		for (int i = 0; i < 200; i++)
		{
			if (!a[i])
				count++;

			if (count <= x)
				res = i + 1;
		}

		cout << res << endl;

	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1330/problem/A
 */
