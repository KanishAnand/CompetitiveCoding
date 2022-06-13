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
    lli n, a, k;
    cin >> n >> k;
    vector<lli> v1, v2;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v1.pb(a);
    }

    for (lli i = 0; i < n; i++) {
        cin >> a;
        a *= k;
        v2.pb(a);
    }

    lli constant = 1e4 + 5;
    vector<vector<lli>> dp(n + 2, vector<lli>(2 * constant + 5, 0));

    dp[0][v1[0] - v2[0] + constant] = v1[0];

    for (lli i = 1; i < n; i++) {
        lli p = v1[i] - v2[i] + constant;
        dp[i][p] = v1[i];
        for (lli j = 0; j <= 2 * constant; j++) {
            if (j - p + constant <= 2 * constant) {
                if (j - p + constant >= 0 && dp[i - 1][j - p + constant] != 0) {
                    dp[i][j] =
                        max(dp[i][j], dp[i - 1][j - p + constant] + v1[i]);
                }
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    if (dp[n - 1][constant] == 0) {
        cout << "-1" << endl;
    } else {
        cout << dp[n - 1][constant] << endl;
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