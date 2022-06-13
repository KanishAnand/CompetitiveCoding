#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, h, l, r;
    cin >> n >> h >> l >> r;
    vector<lli> pref(n + 2, 0);

    fr(i, 0, n) {
        cin >> a;
        pref[i] += a;
        pref[i + 1] += pref[i];
        pref[i] %= h;
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, -1e10));

    if (pref[0] >= l && pref[0] <= r) {
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    if (pref[0] - 1 >= l && pref[0] - 1 <= r) {
        dp[0][1] = 1;
    } else {
        dp[0][1] = 0;
    }

    fr(i, 1, n) {
        // dont't take -1 in this turn
        for (lli j = 0; j <= n; j++) {
            if ((pref[i] - j + 200 * h) % h >= l &&
                (pref[i] - j + 200 * h) % h <= r) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            } else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        // take -1 in this turn
        for (lli j = 0; j < n; j++) {
            if ((pref[i] - j - 1 + 200 * h) % h >= l &&
                (pref[i] - j - 1 + 200 * h) % h <= r) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + 1);
            } else {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j]);
            }
        }
    }

    lli ans = -1;
    fr(i, 0, n + 1) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;

    rt;
}
