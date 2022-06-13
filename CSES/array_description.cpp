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
    lli n, a, m;
    cin >> n >> m;

    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> dp(m + 2, 0), prevdp;

    if (v[0] != 0) {
        dp[v[0]] = 1;
    } else {
        for (lli i = 1; i <= m; i++) {
            dp[i] = 1;
        }
    }

    prevdp = dp;

    for (lli i = 1; i < n; i++) {
        for (lli j = 1; j <= m; j++) {
            dp[j] = 0;
        }
        if (v[i] == 0) {
            for (lli j = 1; j <= m; j++) {
                dp[j] += prevdp[j - 1];
                dp[j] %= MOD;
                dp[j] += prevdp[j];
                dp[j] %= MOD;
                dp[j] += prevdp[j + 1];
                dp[j] %= MOD;
            }
        } else {
            dp[v[i]] += prevdp[v[i] - 1];
            dp[v[i]] %= MOD;
            dp[v[i]] += prevdp[v[i]];
            dp[v[i]] %= MOD;
            dp[v[i]] += prevdp[v[i] + 1];
            dp[v[i]] %= MOD;
        }
        prevdp = dp;
    }

    lli ans = 0;
    for (lli i = 1; i <= m; i++) {
        ans += dp[i];
        ans %= MOD;
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