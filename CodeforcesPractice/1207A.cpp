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
	lli t, b, p, f, h, c;
	vector<lli> v;
	cin >> t;
	while (t--)
	{
		cin >> b >> p >> f;
		cin >> h >> c;
		lli ans = 0;
		if (c > h)
		{
			lli x = min(b / 2, f);
			ans += c * x;
			b -= 2 * x;
			f -= x;
			lli y = min(b / 2, p);
			ans += y * h;
		}
		else
		{
			lli x = min(b / 2, p);
			ans += h * x;
			b -= 2 * x;
			p -= x;
			lli y = min(b / 2, f);
			ans += y * c;
		}
		cout << ans << endl;
	}
	rt;
}
