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


vector<string> prepare;
vector<vector<int>> dp;
vector<string> input;
vector<vector<int>> graph;
string res;
int n, k;

int Decompose(string s, string parten)
{
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		if (parten[i] == '1' && s[i] == '0')
			count++;

		if (parten[i] == '0' && s[i] == '1')
			return -1;
	}

	return count;
}

void enter()
{
	// chuan bi mang prepare
	prepare.push_back("1110111");
	prepare.push_back("0010010");
	prepare.push_back("1011101");
	prepare.push_back("1011011");
	prepare.push_back("0111010");
	prepare.push_back("1101011");
	prepare.push_back("1101111");
	prepare.push_back("1010010");
	prepare.push_back("1111111");
	prepare.push_back("1111011");

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string ts;
		cin >> ts;
		input.push_back(ts);
	}
	// tao vector dp
	for (int i = 0; i <= n; i++)
	{
		vector<int>tv;
		dp.push_back(tv);
		for (int j = 0; j <= k; j++)
			dp[i].push_back(0);
	}

	dp[0][0] = 1;

	// tao vector graph cho moi chuoi tu so thap len so cao
	for (int i = 0; i < n; i++)
	{
		vector<int> tv;
		graph.push_back(tv);
		dp.push_back(tv);
		for (int j = 0; j < 10; j++)
			graph[i].push_back(-1);
	}


	for (int i = n - 1; i > -1; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			int tp = Decompose(input[i], prepare[j]);
			if (tp != -1)
			{
				if (graph[n - 1 - i][j] < tp)
					graph[n - 1 - i][j] = tp;
			}
		}
	}

}


void sovle()
{
	// DP tim tong 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			for (int h = 0; h < 10; h++)
			{
				if (graph[i - 1][h] > -1)
				{
					if (j - graph[i - 1][h] >= 0 && dp[i - 1][j - graph[i - 1][h]])
					{
						dp[i][j] = 1;
					}
				}
			}
		}
	}

	if (dp[n][k] == 0)
		cout << -1 << endl;
	else
	{
		// Tham lam
		for (int i = n; i >= 1; i--)
		{
			for (int j = 9; j > -1; j--)
			{
				if (graph[i - 1][j] > -1)
				{
					if (k - graph[i - 1][j] >= 0 && dp[i - 1][k - graph[i - 1][j]])
					{
						k -= graph[i - 1][j];
						res.push_back((char)(j + 48));
						break;
					}
				}
			}
		}
		cout << res << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	enter();
	sovle();

//	system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1341/problem/D
 */
