#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lli n, a, ans = 200000, ans2 = 2000000;
	vector<lli> v;
	set<lli> st, left, right2;
	cin >> n;
	fr(i, 0, n)
	{
		cin >> a;
		v.pb(a);
		st.insert(a);
	}

	if (st.size() == n)
	{
		cout << "0" << endl;
		rt;
	}

	fr(i, 0, n)
	{
		left.insert(v[i]);
		if (left.size() == i + 1)
		{
			set<lli> right;
			int j;
			for (j = n - 1; j >= 0; j--)
			{
				auto it = left.find(v[j]);
				if (it == left.end())
				{
					right.insert(v[j]);
					if (right.size() != n - j)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			lli val = j - (i + 1) + 1;
			ans = min(ans, val);
		}
		else
		{
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		right2.insert(v[i]);
		if (right2.size() == n - i)
		{
			set<lli> left2;
			int j;
			for (j = 0; j < n; j++)
			{
				if (right2.find(v[j]) == right2.end())
				{
					left2.insert(v[j]);
					if (left2.size() != j + 1)
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			lli val = (i - 1) - j + 1;
			ans2 = min(ans2, val);
		}
		else
		{
			break;
		}
	}

	cout << min(ans2, ans) << endl;
	rt;
}