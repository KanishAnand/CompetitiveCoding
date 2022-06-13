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
    lli w, b;
    cin >> w >> b;
    lli tot = w + b;

    if (w == 0) {
        cout << "0" << endl;
        return;
    }

    vector<vector<double>> dp(tot + 2, vector<double>(w + 2, 0));
    double ans = 0;

    dp[1][0] = double(b) / double(tot);
    ans += double(w) / double(tot);

    for (lli i = 2; i <= tot; i++) {
        for (lli j = 0; j <= min(i - 1, w); j++) {
            if (i % 3 == 1) {
                double pp = double(w - j) / double(tot - i + 1);
                ans += (dp[i - 1][j] * pp);

                pp = double(b - (i - 1 - j)) / double(tot - i + 1);
                dp[i][j] += dp[i - 1][j] * pp;

            } else if (i % 3 == 2) {
                double pp = double(b - (i - 1 - j)) / double(tot - i + 1);
                dp[i][j] += dp[i - 1][j] * pp;
            } else {
                double pp = double(b - (i - 1 - j)) / double(tot - i + 1);
                dp[i][j] += dp[i - 1][j] * pp;

                pp = double(w - j) / double(tot - i + 1);
                dp[i][j + 1] += (dp[i - 1][j] * pp);
            }
        }
    }

    cout << fixed << setprecision(10) << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}