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

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % MOD;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

void solve() {
    lli n, a;
    cin >> n;
    map<lli, lli> mpe, mpo;
    lli xr = 0, ans = 0;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        xr ^= a;
        if (i % 2 == 0) {
            ans += mpe[xr];
            mpe[xr]++;
        } else {
            ans += mpo[xr];
            mpo[xr]++;
        }
        if (xr == 0 && i % 2 == 1) {
            ans++;
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