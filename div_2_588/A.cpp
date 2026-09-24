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

	vector<int> a;
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int ti;
		cin >> ti;
		a.push_back(ti);
		sum += ti;
	}

	sort(a.begin(), a.end());

	if (sum - a[3] == a[3])
		cout << "YES" << endl;
	else
	{
		if (a[3] + a[0] == a[1] + a[2])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1230/problem/A
 */
