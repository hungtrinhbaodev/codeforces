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
	int n;
	vector<LL> a;

	LL res = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		LL ti;
		cin >> ti;
		a.push_back(ti);
	}


	int k = 0;
	while (k < n)
	{
		if (a[k] == 0)
		{
			k++;
		}
		else
		{
			int j = k;
			vector<LL> tv;
			map<LL, LL> m;
			while (j < n && a[j] != 0)
			{
				tv.push_back(a[j]);
				j++;
			}

			m[0] = 2;
			LL sum = 0;
			int minpos = 1;

			for (int i = 0; i < tv.size(); i++)
			{
				sum += tv[i];

				LL k = 1;

				map<LL, LL>::iterator it;
				it = m.find(sum);

				if (it != m.end())
				{
					k = it->second;
				}

				if (k > minpos)
					minpos = k;

				res += (LL)i + 2 - minpos;

				m[sum] = (LL)i + 3;
			}
			k = j;
		}
	}

	cout << res << endl;
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1333/problem/C
 */
