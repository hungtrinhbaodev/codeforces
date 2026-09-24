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

vector<int> primes, checked;	
vector<vector<int>> powOfPrime;
bool isPrime[200007];

int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
void sieve() {

	for (int i = 0; i < 200007; ++i) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i < 200007; ++i) {
		if (isPrime[i] == true) {
			// Mark all the multiples of i as composite numbers
			for (int j = i * i; j < 200007; j += i)
				isPrime[j] = false;
		}
	}

	for (int i = 0; i < 200007; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);	
		}
		checked.push_back(0);
		powOfPrime.push_back(vector<int>());
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	sieve();

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int ti;
		cin >> ti;

		int j = 0;
		while (!isPrime[ti] && ti != 1)
		{
			
			if (ti % primes[j] == 0)
			{
				int k = primes[j];
				checked[k]++;
				int count = 0;
				while (ti % k == 0)
				{
					ti /= k;
					count++;
				}

				powOfPrime[k].push_back(count);
				sort(powOfPrime[k].begin(), powOfPrime[k].end());

				if (powOfPrime[k].size() > 2)
					powOfPrime[k].pop_back();
			}
			j++;
		}

		if (ti != 1)
		{
			checked[ti]++;
			powOfPrime[ti].push_back(1);
			sort(powOfPrime[ti].begin(), powOfPrime[ti].end());

			if (powOfPrime[ti].size() > 2)
				powOfPrime[ti].pop_back();
		}
	}

	LL res = 1;

	for (int i = 0; i < primes.size(); i++)
	{
		if (n - checked[primes[i]] == 0)
		{

			for (int j = 0; j < powOfPrime[primes[i]][1]; j++)
				res *= primes[i];
		}
		else if (n - checked[primes[i]] == 1)
		{
			for (int j = 0; j < powOfPrime[primes[i]][0]; j++)
				res *= primes[i];
		}
	}
	//cout << 127 * 42 / gcd(127, 42) << endl;
	cout << res << endl;
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1350/problem/C
 */
