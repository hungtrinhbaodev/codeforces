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

	int n, k, base = 0;
	vector<vector<int>> a, res;
	vector<vector<bool>> checkRows, checkCols;
	cin >> n >> k;

	// Nhap man hinh
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		vector<bool> tb;
		a.push_back(tv);
		res.push_back(tv);
		checkCols.push_back(tb);
		checkRows.push_back(tb);
		for (int j = 0;j < n; j++)
		{
			char tc;
			cin >> tc;
			if (tc == 'W')
				a[i].push_back(0);
			else
				a[i].push_back(1);

			res[i].push_back(0);
			checkRows[i].push_back(false);
			checkCols[i].push_back(false);
		}
	}

	// Tao bang check row
	// checkRow[i][j] = true 
	// co the lam trang dong thu i neu dat
	// con tro o cot j

	//Xet dong thu i
	for (int i = 0; i  <  n; i++)
	{
		// dem so o den cua dong do
		int count = 0;

		for (int j = 0; j < n; j++)
		{
			if (a[i][j])
				count++;
		}
		
		if (count == 0)
		{
			base++;
			continue;
		}

		//Xet tai k cot cua dong do
		int countK = 0;
		for (int j = 0; j < n - k + 1; j++)
		{
			if (j == 0)
			{
				for (int h = 0; h < k; h++)
				{
					if (a[i][h])
						countK++;
				}

				if (countK == count)
					checkRows[i][j] = true;
			}
			else
			{
				if (a[i][j - 1])
					countK--;

				if (a[i][j - 1 + k])
					countK++;

				if (countK == count)
					checkRows[i][j] = true;
			}
		}
	}


	// Tinh cho bang res tu checkRow

	//Xet tai cot thu i cua moi dong
	for (int i = 0; i < n - k + 1; i++)
	{
		int count = 0;

		// xet k tren tung dong 1
		for (int j = 0; j < n - k + 1; j++)
		{
			if (j == 0)
			{
				for (int h = 0; h < k; h++)
				{
					if (checkRows[h][i])
						count++;
				}

				res[j][i] += count;
			}
			else
			{
				if (checkRows[j - 1][i])
					count--;

				if (checkRows[j - 1 + k][i])
					count++;

				res[j][i] += count;
			}
		
		}

	}


	// Tao bang check cols
	// checkCols[i][j] = true tai cot thu j
	// neu cuc gom da tai dong thu i se lam trang
	// duoc cot nay

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		for (int j = 0; j < n; j++)
		{
			if (a[j][i])
				count++;
		}


		if (count == 0)
		{
			base++;
			continue;
		}


		int countK = 0;

		for (int j = 0; j < n - k + 1; j++)
		{
			if (j == 0)
			{
				for (int h = 0; h < k; h++)
				{
					if (a[h][i])
						countK++;
				}

				if (countK == count)
					checkCols[j][i] = true;
			}
			else
			{
				if (a[j - 1][i])
					countK--;

				if (a[j - 1 + k][i])
					countK++;

				if (countK == count)
					checkCols[j][i] = true;
			}
		}
	}


	// Tinh res tu mang checkCol

	//Xet tren tung dong
	for (int i = 0; i < n - k + 1; i++)
	{
		int count = 0;
		// Xet tung cot
		for (int j = 0; j < n - k + 1; j++)
		{
			if (j == 0)
			{
				for (int h = 0; h < k; h++)
				{
					if (checkCols[i][h])
						count++;
				}
				res[i][j] += count;
			}
			else
			{
				if (checkCols[i][j - 1])
					count--;

				if (checkCols[i][j - 1 + k])
					count++;

				res[i][j] += count;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n - k + 1; i++)
	{
		for (int j = 0; j < n - k + 1; j++)
		{
			if (res[i][j] > max)
				max = res[i][j];
		}
	}


	cout << base + max << endl;
//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1200/problem/D
 */
