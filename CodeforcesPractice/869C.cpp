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
lli dp[5001][5001];

void solve() {
    lli n, a, b, c;
    cin >> a >> b >> c;

    dp[0][0] = 1;
    dp[0][1] = b;
    for (lli i = 1; i < a; i++) {
        dp[i][0] = 1;
        for (lli j = 1; j <= b; j++) {
            dp[i][j] = (dp[i - 1][j - 1]) * (b - (j - 1)) % MOD;
            dp[i][j] %= MOD;
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    lli ans = 0;
    for (lli i = 0; i <= b; i++) {
        ans += dp[a - 1][i];
        ans %= MOD;
    }

    dp[0][0] = 1;
    dp[0][1] = c;
    for (lli i = 1; i < b; i++) {
        dp[i][0] = 1;
        for (lli j = 1; j <= c; j++) {
            dp[i][j] = (dp[i - 1][j - 1]) * (c - (j - 1)) % MOD;
            dp[i][j] %= MOD;
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    lli ans1 = 0;
    for (lli i = 0; i <= c; i++) {
        ans1 += dp[b - 1][i];
        ans1 %= MOD;
    }

    dp[0][0] = 1;
    dp[0][1] = a;
    for (lli i = 1; i < c; i++) {
        dp[i][0] = 1;
        for (lli j = 1; j <= a; j++) {
            dp[i][j] = (dp[i - 1][j - 1]) * (a - (j - 1)) % MOD;
            dp[i][j] %= MOD;
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    lli ans2 = 0;
    for (lli i = 0; i <= a; i++) {
        ans2 += dp[c - 1][i];
        ans2 %= MOD;
    }

    ans *= ans1;
    ans %= MOD;
    ans *= ans2;
    ans %= MOD;
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