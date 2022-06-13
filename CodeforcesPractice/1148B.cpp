#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
    lli n, m, ta, tb, k, a;
    cin >> n >> m >> ta >> tb >> k;
    vector<lli> ab, bc;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        ab.pb(a);
    }
    for (lli i = 0; i < m; i++) {
        cin >> a;
        bc.pb(a);
    }

    if (k >= n || k >= m) {
        cout << "-1" << endl;
        return;
    }

    lli ans = -1;
    for (lli i = 0; i <= k; i++) {
        lli val = ab[i] + ta;
        auto it = lower_bound(bc.begin(), bc.end(), val);
        lli ind = it - bc.begin();
        ind += (k - i);
        if (ind >= m) {
            cout << "-1" << endl;
            return;
        } else {
            ans = max(ans, bc[ind] + tb);
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