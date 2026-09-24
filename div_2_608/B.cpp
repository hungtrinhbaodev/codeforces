#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

vector<int> res;
vector<int> a;

void solve(int d)
{
	int i = 0;
	int n = a.size();
	while (i < n - 1)
	{
		if (a[i] != d)
		{
			int j = i + 1;

			while (a[j] == d)
			{
				res.push_back(j - 1);
				j++;
			}

			res.push_back(j - 1);
			i = j;
		}
		i++;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, count0 = 0, count1 = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'W')
		{
			a.push_back(1);
			count1++;
		}
		else
		{
			a.push_back(0);
			count0++;
		}
	}
	if (count1 % 2 && count0 % 2)
		cout << -1 << endl;
	else
	{
		if (count1 % 2)
		{
			solve(1);
			cout << res.size() << endl;
			for (int i = 0; i < res.size(); i++)
				cout << res[i] + 1<< " ";

			cout << endl;
		}
		else
		{
			solve(0);
			cout << res.size() << endl;
			for (int i = 0; i < res.size(); i++)
				cout << res[i] + 1<< " ";

			cout << endl;
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1271/problem/B
 */
