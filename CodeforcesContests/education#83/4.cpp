#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % mod;
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
lli mod = 998244353;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, m;
    cin >> n >> m;

    if (n == 2 {
        cout << "0" << endl;
        rt;
    }

    lli cur = 0, prev = 0;

    for (lli i = m - (n - 3); i >= 2; i--) {
        prev += (i - 1) % mod;
        prev %= mod;
    }

    if (n == 3) {
        cout << prev << endl;
        rt;
    }

    fr(i, 3, n) {
        if (i % 2 == 0) {
            // dp[i+1]val+1] += dp[i][val];
            cur = prev;
        } else {
            // dp[i+1]val+1] += 2*dp[i][val];
            cur = (2 * prev) % mod;
        }
        prev = cur;
    }
    cout << cur << endl;
    rt;
}
