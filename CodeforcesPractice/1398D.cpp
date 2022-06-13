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
    lli r, g, b, a;
    cin >> r >> g >> b;

    vector<lli> sticks_r, sticks_g, sticks_b;

    for (lli i = 0; i < r; i++) {
        cin >> a;
        sticks_r.pb(a);
    }

    for (lli i = 0; i < g; i++) {
        cin >> a;
        sticks_g.pb(a);
    }

    for (lli i = 0; i < b; i++) {
        cin >> a;
        sticks_b.pb(a);
    }

    sort(sticks_r.rbegin(), sticks_r.rend());
    sort(sticks_g.rbegin(), sticks_g.rend());
    sort(sticks_b.rbegin(), sticks_b.rend());

    vector<vector<vector<lli>>> dp(r + 5, vector<vector<lli>>(g + 5, vector<lli>(b + 5, 0)));
    lli ans = 0;

    for (lli i = 0; i <= r; i++) {
        for (lli j = 0; j <= g; j++) {
            for (lli k = 0; k <= b; k++) {
                if (i != r && j != g) {
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + sticks_r[i] * sticks_g[j]);
                }
                if (j != g && k != b) {
                    dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + sticks_g[j] * sticks_b[k]);
                }
                if (k != b && i != r) {
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + sticks_b[k] * sticks_r[i]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
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