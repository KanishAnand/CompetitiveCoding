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
    double n, p, t;
    cin >> n >> p >> t;

    vector<vector<double>> dp(t + 2, vector<double>(n + 2, 0));
    dp[0][0] = 1;

    for (lli i = 1; i <= t; i++) {
        for (lli j = 0; j <= n; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] * (1 - p);
            } else if (j == n) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * p;
            } else {
                dp[i][j] = dp[i - 1][j] * (1 - p) + dp[i - 1][j - 1] * p;
            }
        }
    }

    double ans = 0;
    for (lli i = 0; i <= n; i++) {
        ans += (dp[t][i] * i);
    }

    cout << fixed << setprecision(8) << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}