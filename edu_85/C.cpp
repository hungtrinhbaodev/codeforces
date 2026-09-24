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
		vector<pair<LL, LL>> a;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			LL ti1, ti2;
			cin >> ti1 >> ti2;
			a.push_back(make_pair(ti1, ti2));
		}

		LL Bullets = 0, minBullets, chancePoint = -1;

		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				Bullets += a[i].first;
			else
			{
				if (a[i].first > a[i - 1].second)
					Bullets += a[i].first - a[i - 1].second;
			}
		}

		minBullets = Bullets;


		if (a[0].first > a[n - 1].second)
			Bullets += a[0].first - a[n - 1].second;

		for (int i = 1; i < n; i++)
		{
			// kiem tra xem co phai diem chuyen dao
			if (a[i].first > a[i - 1].second)
			{
				// diem chuyen giao
				chancePoint = a[i].first - a[i - 1].second;

				// Cap nhat dan
				Bullets = Bullets - a[i - 1].first + a[i].first;

				Bullets -= chancePoint;

				if (Bullets < minBullets)
					minBullets = Bullets;

				Bullets += chancePoint;
			}
			else
			{
				Bullets -= a[i - 1].first;
				Bullets += a[i].first;

				if (Bullets < minBullets)
					minBullets = Bullets;
			}

		}

		cout << minBullets << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1334/problem/C
 */
