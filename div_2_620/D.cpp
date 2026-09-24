#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#define LL long long int
#define module 998244353
using namespace std;
void inv(vector<int>& a, int l, int r)
{
	for (int i = l; i <= (l + r) / 2; i++)
	{
		swap(a[i], a[r - i + l]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		vector<char> b;
		vector<int> a, c;
		int n;
		cin >> n;

		for (int i = 0; i < n - 1; i++)
		{
			char tc;
			cin >> tc;
			b.push_back(tc);
		}

		for (int i = 0; i < n; i++)
		{
			a.push_back(i);
			c.push_back(n - i - 1);
		}

		for (int i = 0; i < n - 1; i++)
		{
			if (b[i] == '<')
			{
				int l = i, r = i;

				while (r < n - 1 && b[r] == '<')
					r++;

				r--;
				//cout << l << " " << r << endl;
				inv(c, l, r + 1);
				i = r;
			}
		}

		for (int i = 0; i < n; i++)
			cout << c[i] + 1 << " ";

		cout << endl;
		for (int i = 0; i < n - 1; i++)
		{
			if (b[i] == '>')
			{
				int l = i, r = i;

				while (r < n - 1 && b[r] == '>')
					r++;

				r--;
				//cout << l << " " << r << endl;
				inv(a, l, r + 1);
				i = r;
			}
		}

		for (int i = 0; i < n; i++)
			cout << a[i] + 1<<" ";
		cout << endl;

	}



	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1304/problem/D
 */
