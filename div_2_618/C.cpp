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


	vector<LL> a;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int ti;

		cin >> ti;

		a.push_back(ti);
	}

	LL k = 1;
	k <<= 32;

	while (k > 0)
	{
		int count = 0, pos = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] & k)
			{
				count++;
				pos = i;
			}
		}

		if (count == 1)
		{
			swap(a[pos], a[0]);
			break;
		}

		k /= 2;

	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1300/problem/C
 */
