#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<set>
#include<stack>
#include<string>
#include<map>
#define pi acos(-1)
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
		int n;
		cin >> n;
		if (n == 1)
			cout<<"FastestFinger" << endl;
		else if (n == 2)
			cout << "Ashishgup" << endl;
		else
		{
			if (n % 2 == 1)
				cout <<"Ashishgup"<< endl;
			else
			{
				int k = n;
				while (n % 2 == 0)
					n /= 2;
				//cout << n << endl;
				if (n == 1)
					cout<<"FastestFinger"<< endl;
				else
				{
					if (k / n == 2)
					{
						bool ac = false;
						for (int i = 3; i <= sqrt(n) && !ac; i+=2)
						{
							if (n % i == 0)
								ac = true;
						}

						if (ac)
							cout << "Ashishgup" << endl;
						else
							cout << "FastestFinger" << endl;
					}
					else
					{
						cout << "Ashishgup" << endl;
					}
				}
			}
		}
	}

	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1370/problem/C
 */
