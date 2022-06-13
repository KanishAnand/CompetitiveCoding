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
    lli n, a, m, k;
    cin >> n >> m >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<vector<lli>> cost(n + 2);
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> a;
            cost[i].pb(a);
        }
    }

    lli inf = 1e15;

    vector<vector<vector<lli>>> dp(
        n + 2, vector<vector<lli>>(m + 2, vector<lli>(k + 2, inf)));

    if (v[0] != 0) {
        dp[0][v[0]][1] = 0;
    } else {
        for (lli i = 1; i <= m; i++) {
            dp[0][i][1] = cost[0][i - 1];
        }
    }

    for (lli i = 1; i < n; i++) {
        if (v[i] == 0) {
            for (lli p = 1; p <= m; p++) {
                for (lli q = 1; q <= m; q++) {
                    for (lli r = 1; r <= k; r++) {
                        if (p == q) {
                            dp[i][p][r] = min(dp[i][p][r],
                                              dp[i - 1][q][r] + cost[i][p - 1]);
                        } else {
                            dp[i][p][r] = min(dp[i][p][r], dp[i - 1][q][r - 1] +
                                                               cost[i][p - 1]);
                        }
                    }
                }
            }
        } else {
            for (lli p = 1; p <= k; p++) {
                for (lli j = 1; j <= m; j++) {
                    if (v[i] == j) {
                        dp[i][v[i]][p] = min(dp[i][v[i]][p], dp[i - 1][j][p]);
                    } else {
                        dp[i][v[i]][p] =
                            min(dp[i][v[i]][p], dp[i - 1][j][p - 1]);
                    }
                }
            }
        }
    }

    lli ans = inf;
    for (lli i = 1; i <= m; i++) {
        ans = min(ans, dp[n - 1][i][k]);
    }

    if (ans == inf) {
        ans = -1;
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