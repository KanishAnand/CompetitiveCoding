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
    lli x, y, l, r;
    cin >> x >> y >> l >> r;
    lli val = 1;

    vector<lli> vx, vy;
    while (1) {
        if (val <= r) {
            vx.pb(val);
        }
        if (val > r) {
            break;
        }

        if (val > r / x) {
            break;
        }
        val *= x;
    }

    val = 1;
    while (1) {
        if (val <= r) {
            vy.pb(val);
        }
        if (val > r) {
            break;
        }
        if (val > r / y) {
            break;
        }
        val *= y;
    }

    vector<lli> v;

    for (lli i = 0; i < vx.size(); i++) {
        for (lli j = 0; j < vy.size(); j++) {
            lli val = vx[i] + vy[j];
            if (val >= l && val <= r) {
                v.pb(val);
            }
        }
    }

    if (v.size() == 0) {
        cout << r - l + 1 << endl;
        return;
    }

    sort(all(v));
    lli ans = 0;

    for (lli i = 1; i < v.size(); i++) {
        val = v[i] - v[i - 1] - 1;
        ans = max(ans, val);
    }

    if (v[0] != l) {
        ans = max(ans, v[0] - l);
    }
    if (v[v.size() - 1] != r) {
        ans = max(ans, r - v[v.size() - 1]);
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