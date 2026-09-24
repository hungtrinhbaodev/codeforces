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



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a[10][10][10][10];
	int b[10][10];
	int res[10][10];
	int count[10][10];
	string s;
	cin >> s;

	// tao mang b 
	for(int i=0;i<10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			b[i][j] = -1;
			res[i][j] = 0;
			count[i][j] = 0;
		}

		for (int j = 9; j > -1; j--)
		{
			int d = (i * j) % 10;
			b[i][d] = j;
		}
	}

	/*
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	*/
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
					a[i][j][x][y] = -1;
			}
		}
	}

	// so lan nho nhat chuyen tu chu so i sang chu so j
	// voi counter x, y
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					int d = j - i;

					if (i > j)
						d = j + 10 - i;

					int res = module;
					// xet cho d truoc

					for (int h = 0; h <= d; h++)
					{
						if (b[x][h] != -1 && b[y][d - h] != -1)
						{
							if (res > b[x][h] + b[y][d - h])
								res = b[x][h] + b[y][d - h];
						}
					}

					// xet cho 10 + d
					d += 10;
					for (int h = 0; h <= d; h++)
					{
						if (h < 10 && d - h < 10 && b[x][h] != -1 && b[y][d - h] != -1)
						{
							if (res > b[x][h] + b[y][d - h])
								res = b[x][h] + b[y][d - h];
						}
					}

					if (res != module)
					{
						a[i][j][x][y] = res;
					}

				}
			}
		}
	}

	// fix truong hop so 0
	for (int i = 0; i < 10; i++)
	{
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				if (x == 0 || y == 0)
					a[i][i][x][y] = 1;
				else
				{
					int res = 10;
					for (int h = 0; h <= 10; h++)
					{
						for (int k = 0; k <= 10; k++)
						{
							if ((k * x + h * y) % 10 == 0)
							{
								if (k+h > 0 && h + k < res)
									res = k + h;
							}
						}
					}
					a[i][i][x][y] = res;
				}
			}
		}
	}

	//tao mang count
	for (int i = 0; i < s.length() - 1; i++)
	{
		count[(int)s[i] - 48][(int)s[i + 1] - 48]++;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					if (count[i][j])
					{
						if (a[i][j][x][y] == -1)
							res[x][y] = -1;
						else
						{
							if (res[x][y] != -1)
							{
								res[x][y] += count[i][j] * a[i][j][x][y];
							}
						}
					}
				}
			}
		}
	}

	/*
	for (int i = 0; i < 10; i++)
	{
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 10; y++)
			{
				cout << i << " " << x << " " << y << " " << a[i][i][x][y] << endl;
			}
		}
	}
	*/
	int d = s.length() - 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (res[i][j] != -1)
				cout << res[i][j] - d<< " ";
			else
				cout << -1 <<" ";
		}

		cout << endl;
	}
	
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1202/problem/B
 */
