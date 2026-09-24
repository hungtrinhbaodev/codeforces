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

	vector<int> prime;
	int k = 2;
	prime.push_back(k);
	while (prime.size() < 11)
	{
		k++;
		bool ac = true;
		for (int i = 2; i <= sqrt(k) && ac; i++)
		{
			if (k % i == 0)
				ac = false;
		}
		if (ac)
			prime.push_back(k);
	}
	
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> res, a, prime_;
		vector<bool> used(11, 0);
		for (int i = 0; i < n; i++)
		{
			int ti;
			cin >> ti;
			int pos = 0;

			while (ti % prime[pos] != 0)
				pos++;

			a.push_back(ti);
			used[pos] = true;
		}

		for (int i = 0; i < 11; i++)
		{
			if (used[i])
				prime_.push_back(prime[i]);
		}
		

		for (int i = 0; i < n; i++)
		{
			int pos = 0;
			while (a[i] % prime_[pos] != 0)
				pos++;
			 
			res.push_back(pos + 1);
		}

		cout << prime_.size() << endl;
		for (int i = 0; i < n; i++)
			cout << res[i] << " ";
		cout << endl;
	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1332/problem/B
 */
