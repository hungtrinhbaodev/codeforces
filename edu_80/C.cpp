#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;



vector<int> a(1027, 0), b(1027, 0), c;

void sieve(vector<int>& a)
{
	int n = a.size();

	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
	}

	a[0] = 0;
	a[1] = 0;

	for (LL i = 2; i < n; i++)
	{
		if (a[i]) {
			for (LL j = i * i; j < n; j += i)
				a[j] = 0;
		}
	}


	for (int i = 0; i < a.size(); i++)
	{
		if (a[i])
			c.push_back(i);
	}

}

void decompose(int p, bool t)
{
	int i = 0;

	while (!a[p] && p != 1)
	{
		while (p % c[i] == 0)
		{
			p /= c[i];
			if (t)
				b[c[i]]++;
			else
				b[c[i]]--;
			//cout << c[i] << " ";
		}
		i++;
	}
	if (t)
		b[p]++;
	else
		b[p]--;
}

LL combined()
{
	LL res = 1;
	for (int i = 2; i < b.size(); i++)
	{
		if (b[i] != 0)
		{
			for (int j = 0; j < b[i]; j++)
				res = (res * i) % module;
		}
	}

	return res;
}


// to hop chap k cua n % 998244353
LL Combination(int n, int k)
{

	// tach n(n-1)..(n-k+) ra so nguyen to
	for (int i = 0; i < k; i++)
	{
		decompose(n - i, 1);
	}


	// tach k! ra so nguyen to
	for (int i = 1; i <= k; i++)
	{
		decompose(i, 0);
	}

	return combined();
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve(a);

	LL n, m;

	cin >> n >> m;

	cout << Combination(n + 2 * m - 1, 2 * m) << endl;

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1288/problem/C
 */
