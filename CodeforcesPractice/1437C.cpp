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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    sort(all(v));

    vector<vector<lli>> dp(n + 2, vector<lli>(2 * n + 2, 0));

    for (lli i = 0; i < n; i++) {
        for (lli j = 1; j <= 2 * n; j++) {
            lli val = abs(j - v[i]);
            if (i != 0) {
                lli mn = 1e5;
                for (lli k = 1; k < j; k++) {
                    mn = min(mn, dp[i - 1][k]);
                }
                val += mn;
            }
            dp[i][j] = val;
        }
    }

    lli ans = 1e5;
    for (lli i = 1; i <= 2 * n; i++) {
        ans = min(ans, dp[n - 1][i]);
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