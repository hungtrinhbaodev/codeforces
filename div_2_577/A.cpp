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
	
	vector<int> a;
	vector<vector<int>> b;
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < 5; i++)
	{
		vector<int> tv;
		b.push_back(tv);
		for (int j = 0; j < m; j++)
		{
			b[i].push_back(0);
		}
	}

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			b[(int)(s[j] - 65)][j]++;
		}
	}


	for (int i = 0; i < m; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
	}

	LL sum = 0;

	for (int i = 0; i < m; i++)
	{
		LL temp = 0;

		for (int j = 0; j < 5; j++)
		{
			if (b[j][i] > temp)
				temp = b[j][i];
		}

		sum += temp * a[i];
	}


	cout << sum << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1201/problem/A
 */
