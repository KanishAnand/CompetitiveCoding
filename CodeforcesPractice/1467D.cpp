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
#define len(x) (lli)(x.length())
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

lli dp[5003][5003];

void solve() {
    lli n, a, k, q;
    cin >> n >> k >> q;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (lli i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (lli i = 1; i <= k; i++) {
        for (lli j = 0; j < n; j++) {
            if (j != 0) {
                dp[j][i] += dp[j - 1][i - 1];
                dp[j][i] %= MOD;
            }
            if (j != n - 1) {
                dp[j][i] += dp[j + 1][i - 1];
                dp[j][i] %= MOD;
            }
        }
    }

    vector<lli> cnt(n + 2, 0);
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j <= k; j++) {
            cnt[i] += (dp[i][j] * dp[i][k - j]) % MOD;
            cnt[i] %= MOD;
        }
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        ans += (cnt[i] * v[i]) % MOD;
        ans %= MOD;
    }

    lli ind, x;
    while (q--) {
        cin >> ind >> x;
        ind--;
        lli val = cnt[ind] * (x - v[ind] + MOD);
        val %= MOD;
        ans += val;
        ans %= MOD;
        v[ind] = x;
        cout << ans << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}