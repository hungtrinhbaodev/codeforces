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



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> minQ, maxQ;
		map<int, int> Map;
		vector<int> a;
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			a.push_back(ti);
		}


		for (int i = 0; i < n / 2; i++)
		{
			Map[a[i] + a[n - 1 - i]]++;
			if (a[i] > a[n - 1 - i])
			{
				minQ.push_back(a[n - 1 - i]);
				maxQ.push_back(a[i]);
			}
			else
			{
				minQ.push_back(a[i]);
				maxQ.push_back(a[n - 1 - i]);
			}
		}

		sort(minQ.begin(), minQ.end());
		sort(maxQ.begin(), maxQ.end());

		map<int, int>::iterator it;
		int res = n / 2, q = 0;
		for (it = Map.begin(); it != Map.end(); it++)
		{
			int sum = it->first;

			if (sum > k)
			{
				sum -= k;

				vector<int>::iterator up = lower_bound(maxQ.begin(), maxQ.end(), sum );

				int pos = up - maxQ.begin();
				//cout << pos << endl;
				int tempRes = pos * 2 + (n / 2 - pos) - it->second;

				if (tempRes < res)
				{
					res = tempRes;
				}

			}
			else if(sum < k)
			{
				vector<int>::iterator low = upper_bound(minQ.begin(), minQ.end(), sum - 1);

				int pos = low - minQ.begin();

				int  tempRes = pos + (n / 2 - pos) * 2 - it->second;

				if (tempRes < res)
				{
					res = tempRes;
				}
			}
			else
			{
				vector<int>::iterator low = upper_bound(minQ.begin(), minQ.end(), k - 1);

				int pos = low - minQ.begin();

				int  tempRes = pos + (n / 2 - pos) * 2 - it->second;

				if (tempRes < res)
				{
					res = tempRes;
				}
			}
		}

		
		cout << res << endl;
	}
	


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1343/problem/D
 */
