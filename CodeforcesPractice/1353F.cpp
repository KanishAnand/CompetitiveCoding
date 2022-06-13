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

void solve() {
    lli n, a, m;
    cin >> n >> m;
    vector<vector<lli>> arr(n + 2);
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> a;
            arr[i].pb(a);
        }
    }

    lli ans = -1, start;
    lli inf = 1e18;

    for (lli ii = 0; ii < n; ii++) {
        for (lli jj = 0; jj < m; jj++) {
            vector<vector<lli>> dp(n + 2, vector<lli>(m + 2, inf));
            lli p = arr[ii][jj] - ii - jj;
            start = p;
            p = arr[0][0] - p;
            if (p < 0) {
                continue;
            }
            dp[0][0] = p;
            for (lli i = 0; i < n; i++) {
                for (lli j = 0; j < m; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    lli val = start + i + j;
                    val = arr[i][j] - val;
                    if (val < 0) {
                        continue;
                    }
                    if (i == 0) {
                        dp[i][j] = dp[i][j - 1];
                    } else if (j == 0) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    }
                    dp[i][j] += val;
                }
            }

            if (ans == -1) {
                ans = dp[n - 1][m - 1];
            } else {
                ans = min(ans, dp[n - 1][m - 1]);
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}