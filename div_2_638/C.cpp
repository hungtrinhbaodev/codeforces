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
		vector<int> a(26, 0);
		int n, k;
		cin >> n >> k;
		string s,res;
		cin >> s;

		for (int i = 0; i < n; i++)
			a[(int)(s[i] - 97)]++;
		
		int i = 0;

		while (i < 26 && a[i] == 0)
			i++;

		if (a[i] < k)
		{
			int tempSum = 0;
			while (i < 26)
			{
				if (a[i] != 0)
				{
					tempSum += a[i];
					if (tempSum >= k)
					{
						cout << (char)(i + 97) << endl;
						break;
					}
				}
				i++;
			}
		}
		else
		{
			a[i] -= k;

			cout << (char)(i + 97);
			
			int count = 0,pos = 0;

			for (int j = 0; j < 26; j++)
			{
				if (a[j] > 0)
				{
					count++;
					pos = j;
				}
			}

			if (count > 1)
			{
				while (i < 26)
				{
					if (a[i] != 0)
					{
						for (int j = 0; j < a[i]; j++)
						{
							cout << (char)(i + 97);
						}
					}
					i++;
				}
				cout << endl;
			}
			else
			{
				int m;
				if (a[pos] % k == 0)
					m = a[pos] / k;
				else
					m = a[pos] / k + 1;
				

				for (int j = 0; j < m; j++)
					cout << (char)(pos + 97);

				cout << endl;
			}
		}
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1348/problem/C
 */
