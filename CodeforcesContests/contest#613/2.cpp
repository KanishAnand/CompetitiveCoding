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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<lli> v;
        lli sum = 0;
        fr(i, 0, n) {
            cin >> a;
            sum += a;
            v.pb(a);
        }
        vector<lli> dp(n + 2, 0);
        dp[0] = v[0];
        lli flag = 0;
        if (dp[0] >= sum) {
            flag = 1;
        }
        fr(i, 1, n - 1) {
            dp[i] = max(v[i] + dp[i - 1], v[i]);
            if (dp[i] >= sum) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            dp[1] = v[1];
            fr(i, 2, n) {
                dp[i] = max(v[i] + dp[i - 1], v[i]);
            }
        }

        if (dp[n - 1] >= sum) {
            flag = 1;
        }

        if (flag == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    rt;
}