#include<iostream>
#include<vector>
#define LL long long int
using namespace std;

int main()
{

	int t;
	cin >> t;
	while (t--)
	{
		int n, kmin = 1;
		string s,  smin;

		cin >> n;
		cin >> s;

		smin = s;

		for (int i = 2; i <= n; i++)
		{
			int tchance = n - i + 1;
			string s1, s2;


			for (int j = i - 1; j < n; j++)
				s1 += s[j];

			for (int j = 0; j < i - 1; j++)
				s2 += s[j];

			if (tchance % 2)
				for (int j = 0; j < s2.length()/2; j++)
					swap(s2[j],s2[s2.length() - 1 - j]);

			s1 = s1 + s2;

			if (s1 < smin)
			{
				smin = s1;
				kmin = i;
			}
		}

		cout << smin << endl;
		cout << kmin << endl;

	}


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1316/problem/B
 */
