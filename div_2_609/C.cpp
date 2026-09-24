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

	int n, k;
	cin >> n >> k;
	string s1,s2,ds;
	cin >> s1;

	for (int i = 0; i < k; i++)
	{
		ds.push_back(s1[i]);
	}

	while (s2.length() < s1.length())
		s2 = s2 + ds;

	while (s2.length() > s1.length())
		s2.pop_back();


	if (s1 <= s2)
	{
		cout << s2.length() << endl;
		cout << s2 << endl;
	}
	else
	{
		int pos = ds.length() - 1;
		while (ds[pos] == '9')
		{
			ds[pos] = '0';
			pos--;
		}
		ds[pos]++;

		s2.clear();
		while (s2.length() < s1.length())
			s2 = s2 + ds;

		while (s2.length() > s1.length())
			s2.pop_back();


		cout << s2.length() << endl;
		cout << s2 << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1269/problem/C
 */
