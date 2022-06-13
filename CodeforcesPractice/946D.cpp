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
    lli n, a, m, k;
    cin >> n >> m >> k;
    string st;
    vector<vector<lli>> store(n + 2, vector<lli>(m + 2, 1e10));

    for (lli i = 0; i < n; i++) {
        cin >> st;
        lli one = 0;
        vector<lli> tmp;
        for (lli q = 0; q < st.length(); q++) {
            if (st[q] == '1') {
                one++;
                tmp.pb(q);
            }
        }

        store[i][one] = 0;

        for (lli q = 1; q <= one; q++) {
            lli ans = 1e10;
            for (lli j = 0; j <= tmp.size() - q; j++) {
                lli val = tmp[j + q - 1] - tmp[j] + 1;
                ans = min(ans, val);
            }
            store[i][one - q] = ans;
        }
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(k + 2, 1e10));

    for (lli i = 0; i <= min(m, k); i++) {
        dp[0][i] = store[0][i];
    }

    for (lli i = 1; i < n; i++) {
        for (lli j = 0; j <= k; j++) {
            for (lli r = 0; r <= j; r++) {
                if (j - r <= m) {
                    lli val = dp[i - 1][r] + store[i][j - r];
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
    }

    lli ans = 1e10;
    for (lli i = 0; i <= k; i++) {
        ans = min(ans, dp[n - 1][i]);
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