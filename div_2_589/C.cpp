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


int const N = 100001;
int isPrime[N];
vector<LL> primeOfX;
LL x, n;

void sieve() {

	for (int i = 0; i < N; ++i) {
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i * i < N; ++i) {
		if (isPrime[i] == true) {
			// Mark all the multiples of i as composite numbers
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
		}
	}
}

void Decompose()
{
	LL c = x;
	for (int i = 0; i < N; i++)
	{
		if (isPrime[i])
		{
			if (c % i == 0)
			{
				primeOfX.push_back(i);
				while (c % i == 0)
					c /= i;
			}
		}
	}

	if (c != 1)
		primeOfX.push_back(c);
}

LL powOfNum(LL x, LL pow, LL modu)
{
	LL y = x, res = 1;
	while (pow > 0)
	{
		if (pow & 1)
		{
			res *= y;
			res %= modu;
		}
		y *= y;
		y %= modu;
		pow >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sieve();
	cin >> x >> n;
	Decompose();

	LL res = 1;
	for (int i = 0; i < primeOfX.size(); i++)
	{
		LL num = primeOfX[i];
		LL j = 1;

		while (true)
		{
			LL k = n / num;
			k = k - k / primeOfX[i];

			res *= powOfNum(primeOfX[i], j*k, module);
			res %= module;

			j++;
			num *= primeOfX[i];

			if (n / num < primeOfX[i])
				break;
		}

		LL k = n / num;
		k = k - k / primeOfX[i];

		res *= powOfNum(primeOfX[i], j * k, module);
		res %= module;
	}

	cout << res << endl;

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1228/problem/C
 */
