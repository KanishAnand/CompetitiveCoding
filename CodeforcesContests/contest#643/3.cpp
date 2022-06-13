#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli a, b, c, d;
    cin >> a >> b >> c >> d;
    lli no = d - c + 1, ans = 0;

    for (lli i = a; i <= b; i++) {
        lli val = c + 1 - i, p;

        if (val >= b && val <= c) {
            p = c - val + 1;
            if (d - c + 1 >= p) {
                ans += (p * (p + 1)) / 2;
            } else {
                lli q = d - c + 1;
                ans += (p * (p + 1)) / 2;
                ans -= ((p - q) * (p - q + 1)) / 2;
            }
        } else if (val <= b) {
            lli pp = b + i - 1;
            lli qq = pp - c;
            qq = min(qq, d - c + 1);
            ans += qq * (c - b + 1);

            lli ll = d - pp + 1;
            if (ll > 0) {
                lli oo = c - b + 1;
                ans += (oo * (oo + 1)) / 2;
                if (ll < oo) {
                    oo -= ll;
                    ans -= (oo * (oo + 1)) / 2;
                }
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}