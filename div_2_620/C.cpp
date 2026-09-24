#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#define LL long long int
#define module 998244353
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
		vector<pair<LL, LL>> temp;
		vector<LL> time;
		int n, m;
		cin >> n >> m;


		for (int i = 0; i < n; i++)
		{
			LL h, l, t;
			cin >> t >> l >> h;
			time.push_back(t);
			temp.push_back(make_pair(l, h));
		}

		LL maxl = m, minl = m, tl = 0;
		LL minT = -1, maxT = -1;
		bool ac = true;
		for (int i = 0; i < n && ac; i++)
		{	
			minT = temp[i].first;
				
			maxT = temp[i].second;


			maxl += (time[i] - tl);
			minl -= (time[i] - tl);
			tl = time[i];

			if (maxl < minT || minl > maxT)
				ac = false;

			if (maxl >= maxT)
				maxl = maxT;

			if (minl <= minT)
				minl = minT;

		}


		if (ac)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}



//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1304/problem/C
 */
