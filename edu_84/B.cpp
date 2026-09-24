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
	int t;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		vector<bool> a(n,false), b(n,false);

		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			bool ac = false;
			for (int j = 0; j < k; j++)
			{
				int ti;
				cin >> ti;

				if (!b[ti - 1] && !ac)
				{
					a[i] = true;
					b[ti - 1] = true;
					ac = true;
				}
			}

		}


		int pos1 = -1, pos2 = -1;

		for (int i = 0; i < n; i++)
		{
			if (pos1 == -1)
				if (!a[i])
					pos1 = i;

			if (pos2 == -1)
				if (!b[i])
					pos2 = i;
		}
		if (pos1 == -1)
			cout << "OPTIMAL" << endl;
		else
		{
			cout << "IMPROVE" << endl;
			cout << pos1 + 1 << " " << pos2 + 1 << endl;
		}

	}



	//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1327/problem/B
 */
