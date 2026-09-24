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

	int t;
	cin >> t;
	while (t--)
	{
		vector<int> leta(26, 0), letb(26,0);
		string a, b;
		cin >> a >> b;

		for (int i = 0; i < a.size(); i++)
		{
			leta[(int)a[i] - 97]++;
		}


		if (a.size() > b.size())
			cout << "NO" << endl;
		else
		{
			bool ac = false;
			for (int i = 0; i < b.size() && !ac; i++)
			{
				for (int j = i; j < i + a.size() && j < b.size(); j++)
				{
					letb[(int)b[j] - 97]++;
				}

				ac = true;

				for (int j = 0; j < 26; j++)
				{
					if (leta[j] != letb[j])
						ac = false;

					letb[j] = 0;
				}
			}


			if (ac)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1278/problem/A
 */
