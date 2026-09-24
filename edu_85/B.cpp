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
		LL n,x;
		cin >> n >> x;
		vector<LL> a;
		LL sum = 0;
		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			a.push_back(ti);
			sum += ti;
		}

		if (sum / n >= x)
			cout << n << endl;
		else
		{
			sort(a.begin(), a.end());
			int res = 0;
			for (LL i = 0; i < n - 1; i++)
			{
				sum -= a[i];
				//cout << sum << " " << n - i - 1 << endl;
				if (sum / (n - i - 1) >= x)
				{
					res = (n - i - 1);
					break;
				}
			}

			cout << res << endl;
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1334/problem/B
 */
