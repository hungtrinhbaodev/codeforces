#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#define LL long long int
#define module 998244353
using namespace std;

bool checkPalindrome(string a)
{
	bool ac = true;

	for (int i = 0; i < a.size() / 2 && ac; i++)
	{
		if (a[i] != a[a.size() - 1 - i])
			ac = false;
	}
	return ac;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> a;
	vector<bool> check, used;
	vector<vector<int>> pair;
	string res;
	stack<string> S;

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		bool tb = false;
		vector<int> tv;
		string ts;
		check.push_back(tb);
		used.push_back(tb);
		pair.push_back(tv);
		cin >> ts;
		a.push_back(ts);
		cin.ignore();
	}

	for (int i = 0; i < n; i++)
	{
		check[i] = checkPalindrome(a[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			string ts;
			ts = a[i] + a[j];
			
			if (checkPalindrome(ts))
			{
				pair[i].push_back(j);
				//cout << ts << endl;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < pair[i].size(); j++)
		{
			if (!used[i] && !used[pair[i][j]])
			{
				res += a[i];
				S.push(a[pair[i][j]]);
				used[i] = true;
				used[pair[i][j]] = true;

				break;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		if (check[i] && !used[i])
		{
			res += a[i];
			break;
		}
	}

	while (!S.empty())
	{
		res += S.top();
		S.pop();
	}


	cout << res.size() << endl;
	cout << res << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1304/problem/B
 */
