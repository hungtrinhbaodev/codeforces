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
		string odd, even;
		string a,res;
		cin >> a;

		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] % 2 == 0)
				even.push_back(a[i]);
			else
				odd.push_back(a[i]);
		}
		

		int i = 0, j = 0;
		while (j < even.length() && i < odd.length())
		{
			if (even[j] < odd[i])
			{
				res.push_back(even[j]);
				j++;
			}
			else
			{
				res.push_back(odd[i]);
				i++;
			}
		}

		while (i < odd.length())
		{
			res.push_back(odd[i]);
			i++;
		}

		while (j < even.length())
		{
			res.push_back(even[j]);
			j++;
		}


		cout << res << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1251/problem/C
 */
