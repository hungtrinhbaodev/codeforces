#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
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
		// phan tu i trong mang min, max luu vi tri 
		// co toa do x nho nhat, lon nhat tuong ung tai 
		// dong thu i
		int max[1007], min[1007];
		string res;

		// gan gia tri lon nhat cho mang nho nhat
		// gia tri nho nhat cho mang lon nhat
		for (int i = 0; i < 1007; i++)
		{
			min[i] = 1001;
			max[i] = -1;
		}
		// dong thu 0 vi tri co toa do x nho nhat la 0 
		// o bat dau
		min[0] = 0;
		max[0] = 0;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int x, y;

			cin >> x >> y;

			// tai dong y xet xem x dc nhap vao 
			// co phai la x be nhat
			if (min[y] > x)
				min[y] = x;

			// tuong tu voi lon nhat
			if (max[y] < x)
				max[y] = x;
		}
		
		int i = 0;
		int ac = 1;
		// Xet tung dong 1;
		while (i < 1001 && ac)
		{
			// xet xem phai di qua phai
			// tren dong do bn lan
			int n = max[i] - min[i];

			for (int j = 0; j < n; j++)
				res = res + 'R';
			
			// Luu lai vi tri hien hanh
			int k = i, d;

			// tang i len 1 de xet dong tiep theo
			i = i + 1;

			// Tim xem dong nao o tren gan nhat
			while (i < 1001 && min[i] == 1001)
				i++;

			// Neu i qua dong cuoi r thi ko can xet tiep nua
			if (i == 1001)
				break;

			// Di qua phai tuong ung bang doan nay
			d = min[i] - max[k];

			// Luc nay cuc trai cung cua dong tren
			// nam ben phai cuc phai cung cua dong
			// duoi vay thi khong di duoc
			if (d < 0)
				ac = 0;

			// Di qua phai so lan bang khoang cach 
			// cuc phai cung dong duoi cho den cuc trai
			// cung cua dong tren de co cai duong dan
			// nho nhat
			for (int j = 0; j < d; j++)
				res = res + 'R';

			// di len dung bang doan khoang cach
			for (int j = 0; j < i - k; j++)
				res = res + 'U';
		}


		if (ac == 1)
		{
			cout << "YES" << endl;
			cout << res << endl;
		}
		else
			cout << "NO" << endl;

	}
	//system("pause");
	return 0;
}


/**
 * link contest: https://codeforces.com/contest/1294/problem/B
 */
