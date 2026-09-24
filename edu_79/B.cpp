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
	while (t--)
	{
		LL n, s;
		vector<LL> a;
		cin >> n >> s;
		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			a.push_back(ti);
		}

		int max = -1, posMax = -1;
		LL sum = 0;
		
		int i = 0;

		while (i < n && sum < s)
		{
			sum += a[i];
			if (a[i] > max)
			{
				max = a[i];
				posMax = i;
			}
			i++;
		}
		
		if (i == n)
			cout << 0 << endl;
		else
		{
			if (a[i] < max)
				cout << posMax + 1 << endl;
			else
				cout << 0 << endl;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1279/problem/B
 */
