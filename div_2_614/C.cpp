#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<vector<int>> a;

	for (int i = 0; i < 2; i++)
	{
		vector<int> tv;
		a.push_back(tv);
		
		for (int j = 0; j < n; j++)
			a[i].push_back(0);
	}

	int count = 0;
	while (q--)
	{
		int x, y;

		cin >> x >> y;

		x--;
		y--;

		if (!a[x][y])
		{
			for (int i = y - 1; i <= y + 1; i++)
			{
				if (i > -1 && i < n)
				{
					if (a[1 - x][i])
					{
						count++;
					}

				}
			}
			a[x][y] = 1;
		}
		else
		{
			for (int i = y - 1; i <= y + 1; i++)
			{
				if (i > -1 && i < n)
				{
					if (a[1 - x][i])
						count--;
				}
			}
			a[x][y] = 0;

		}

	//	cout << count << endl;
		if (!count)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}


//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1293/problem/C
 */
