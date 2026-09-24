#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#define LL long long int
#define module 1000000007
using namespace std;

vector<int> res;
vector<int> a;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sx, sy, resx, resy, cl = 0, cr = 0, cd = 0, cu = 0, max1, max2;
	cin >> n >> sx >> sy;
	resx = sx;
	resy = sy;
	for (int i = 0; i < n; i++)
	{
		int x, y;

		cin >> x >> y;

		if (x > sx)
			cr++;
		else if (x < sx)
			cl++;

		if (y > sy)
			cd++;
		else if (y < sy)
			cu++;

	}

	if (cu > cd)
	{
		resy--;
		max1 = cu;
	}
	else
	{
		resy++;
		max1 = cd;
	}

	if (cl > cr)
	{
		resx--;
		max2 = cl;
	}
	else
	{
		resx++;
		max2 = cr;
	}

	if (max1 > max2)
		cout << max1 << endl << sx << " " << resy << endl;
	else
		cout << max2 << endl << resx << " " << sy << endl;


	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1271/problem/C
 */
