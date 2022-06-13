#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve)
{
	lli val;
	for (lli i = 0; i < n; i++)
	{
		cin >> val;
		ve.pb(val);
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n;
	vector<lli> v;
	cin >> n;
	lli arr[n][n];
	arr[0][0] = 8;
	arr[0][1] = 9;
	arr[0][2] = 1;
	arr[0][3] = 13;
	arr[1][0] = 3;
	arr[1][1] = 12;
	arr[1][2] = 7;
	arr[1][3] = 5;
	arr[2][0] = 0;
	arr[2][1] = 2;
	arr[2][2] = 4;
	arr[2][3] = 11;
	arr[3][0] = 6;
	arr[3][1] = 10;
	arr[3][2] = 15;
	arr[3][3] = 14;

	lli no_of_grids = n / 4;
	lli p = 16, q = 16 * (no_of_grids);

	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			lli x = i / 4, y = j / 4;
			arr[i][j] = arr[i % 4][j % 4] + y * p + x * q;
		}
	}

	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	rt;
}
