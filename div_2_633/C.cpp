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
		LL n, res = -1;
		vector<LL> a;
		stack<LL> s;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			LL ti;
			cin >> ti;
			a.push_back(ti);
		}

		LL minpos = module;
		for (int i = 0; i < n; i++)
		{
			if (s.empty())
				s.push(a[i]);
			else
			{
				if (s.top() < a[i])
				{
					if (minpos != module)
					{
						LL k = s.top() - minpos;
						LL d = 1, count = 0;

						while (k>0)
						{
							k>>=1;
							count++;
						}

						if (res == -1)
							res = count;
						else
							if (res < count)
								res = count;
					}

					minpos = module;
					s.push(a[i]);
				}
				else
				{
					if (a[i] < minpos)
						minpos = a[i];
				}
			}
		}

		if (minpos != module)
		{
			LL k = s.top() - minpos;
			LL d = 1, count = 0;
			while (k > 0)
			{
				k >>= 1;
				count++;
			}

			if (res == -1)
				res = count;
			else
				if (res < count)
					res = count;
		}

		if (res == -1)
			res = 0;

		cout << res << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1339/problem/C
 */
