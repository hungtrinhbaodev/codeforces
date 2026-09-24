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

	int n;
	cin >> n;
	string a,b;
	vector<LL> tv;
	cin >> a;

	LL d = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != a[i + 1])
			d++;
	}


	stack<LL> s;
	b = 'A' + a;
	b += 'A';

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == 'A')
			s.push(i);
	}
	
	int j = 0;

	while (1)
	{
		j = s.top();
		s.pop();
		if (!s.empty())
			tv.push_back(j - s.top() - 1);
		else
			break;
	}

	LL res = (LL)n * (LL)(n + 1) / 2, k = 0;

	for (int i = 0; i < tv.size() - 1; i++)
	{
		k += tv[i] + tv[i + 1];
	}


	b.clear();
	b = 'B' + a;
	b += 'B';

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == 'B')
			s.push(i);
	}

	tv.clear();
	while (1)
	{
		j = s.top();
		s.pop();
		if (!s.empty())
			tv.push_back(j - s.top() - 1);
		else
			break;
	}


	for (int i = 0; i < tv.size() - 1; i++)
	{

		k += tv[i] + tv[i + 1];
	}
	
	cout << res - (k + n) + d << endl;
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1238/problem/D
 */
