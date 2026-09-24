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
	stack<char> s;

	int n, count0 = 0, count1 = 0;
	string a;
	cin >> n;
	cin >> a;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == '(')
			count1++;
		else
			count0++;
	}

	if (count1 != count0)
		cout << -1 << endl;
	else
	{
		int res = 0 ,pre = 0;

		count0 = count1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (s.empty())
			{
				s.push(a[i]);
				if (a[i] == ')')
				{
					count0++;
					pre = i;
				}
			}
			else
			{
				if (!count0)
				{
					if (a[i] == ')')
					{
						s.pop();
					}
					else
					{
						s.push(a[i]);
					}
				}
				else
				{
					if(a[i] == ')')
					{
						if (s.top() == '(')
						{
							s.pop();
							count1--;
						}
						else
						{
							s.push(a[i]);
							count0++;
						}
					}
					else
					{
						s.push(a[i]);
						count1++;
					}

					if (count0 == count1)
					{
						res += i - pre + 1;
						while (!s.empty())
							s.pop();
						count0 = count1 = 0;
					}
				}
			}
		}
		cout << res << endl;
	}

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1323/problem/C
 */
