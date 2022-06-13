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
const lli MOD = 998244353;
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
    lli n, m, q, a;
    cin >> m >> n >> q;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    vector<lli> query;
    for (lli i = 0; i < q; i++) {
        cin >> a;
        query.pb(a);
    }

    vector<vector<lli>> dp(m + 2, vector<lli>(n + 2, 0));
    dp[0][0] = v[0] % MOD;

    for (lli i = 1; i < n; i++) {
        dp[0][i] += (dp[0][i - 1] * v[i]) % MOD;
        dp[0][i] %= MOD;
    }

    for (lli i = 1; i < m; i++) {
        for (lli j = 0; j < n; j++) {
            lli val = 0;
            val = (dp[i - 1][j] * v[j]) % MOD;
            if (j != 0) {
                val += (dp[i][j - 1] * v[j]) % MOD;
                val %= MOD;
            }
            dp[i][j] = val;
        }
    }

    for (lli i = 0; i < query.size(); i++) {
        cout << dp[query[i] - 1][n - 1] << endl;
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