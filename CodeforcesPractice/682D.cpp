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

lli dp[1002][1002][12][2];

void solve() {
    lli n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            for (lli p = 1; p <= k; p++) {
                if (i != 0) {
                    dp[i][j][p][0] = max({dp[i][j][p][0], dp[i - 1][j][p][0], dp[i - 1][j][p][1]});
                }
                if (j != 0) {
                    dp[i][j][p][0] = max({dp[i][j][p][0], dp[i][j - 1][p][0], dp[i][j - 1][p][1]});
                }
                if (i != 0 && j != 0) {
                    dp[i][j][p][0] = max({dp[i][j][p][0], dp[i - 1][j - 1][p][0], dp[i - 1][j - 1][p][1]});
                }

                if (s[i] == t[j]) {
                    if (i != 0 && j != 0) {
                        dp[i][j][p][1] = max({dp[i][j][p][1], dp[i - 1][j - 1][p - 1][0] + 1, dp[i - 1][j - 1][p - 1][1] + 1});
                        if (s[i - 1] == t[j - 1]) {
                            dp[i][j][p][1] = max(dp[i][j][p][1], dp[i - 1][j - 1][p][1] + 1);
                        }
                    } else {
                        dp[i][j][p][1] = max(dp[i][j][p][1], 1ll);
                    }
                }
            }
        }
    }

    lli ans = max(dp[n - 1][m - 1][k][0], dp[n - 1][m - 1][k][1]);
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