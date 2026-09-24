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

	LL res = 0;
	int n, m, k;
	cin >> n >> m >> k;
	vector<LL> hashRows(n+1,0), hashCols(m+1,0);


	stack<int> ts;

	ts.push(0);
	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;
		if (ti == 0)
			ts.push(i + 1);
	}

	int j = n + 1;
	while (1)
	{
		if (ts.empty())
			break;
		
		int d = j - ts.top() - 1;
		for (int i = 1; i <= d; i++)
		{
			hashRows[i] += (LL)d - i + 1;
		}
		j = ts.top();
		ts.pop();
	}

	ts.push(0);
	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		if (ti == 0)
			ts.push(i + 1);
	}

	j = m + 1;
	while (1)
	{
		if (ts.empty())
			break;

		int d = j - ts.top() - 1;
		for (int i = 1; i <= d; i++)
		{
			hashCols[i] += (LL)d - i + 1;
		}
		j = ts.top();
		ts.pop();
	}


	for (int i = 1; i <= sqrt(k); i++)
	{
		if (k % i == 0)
		{
			j = k / i;
			if (i <= m && j <= n)
			{
				res += (LL)hashCols[i] * hashRows[j];
				//cout << hashCols[i] << " " << hashRows[j] << endl;
			}
			if (i <= n && j <= m && i != j)
			{
				res += (LL)hashCols[j] * hashRows[i];
				//cout << hashCols[j] << " " << hashRows[i] << endl;
			}
		}
	}

	cout << res << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1323/problem/B
 */
