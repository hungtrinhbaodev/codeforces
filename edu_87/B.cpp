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
		string s;
		cin >> s;

		vector<int> hash(3, 0);
		int j = 0;
		int res = module;
		for (int i = 0; i < s.size(); i++)
		{
			hash[(int)s[i] - 49]++;
			bool ac = true;
			for (int k = 0; k < 3; k++)
			{
				if (hash[k] <= 0)
					ac = false;
			}
			if (ac)
			{
				while (1)
				{
					if (hash[(int)s[j] - 49] - 1 == 0)
						break;
					hash[(int)s[j] - 49]--;
					j++;
				}

				if (i - j + 1 < res)
					res = i - j + 1;
			}
		}

		if (res == module)
			res = 0;
		cout << res << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1354/problem/B
 */
