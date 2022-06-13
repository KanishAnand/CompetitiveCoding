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
    lli n, a, b, c, d;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    if (n == 1) {
        cout << v[0] << endl;
        return;
    }

    vector<lli> dp(n + 10, n + 10);

    dp[1] = v[0];
    dp[2] = v[0];
    dp[2] = min(dp[2], v[0] + v[1]);
    dp[3] = v[0] + v[1];

    for (lli i = 1; i < n; i++) {
        a = n + 5, b = n + 5, c = n + 5, d = n + 5;

        if (i >= 2) {
            a = dp[i - 2] + v[i - 1];
        }
        if (i >= 3) {
            b = dp[i - 3] + v[i - 1] + v[i - 2];
            c = dp[i - 3] + v[i - 2];
        }
        if (i >= 4) {
            d = dp[i - 4] + v[i - 2] + v[i - 3];
        }

        dp[i] = min({dp[i], a, b, c, d});
    }

    lli ans = dp[n - 1];
    if (n >= 2) {
        ans = min(ans, dp[n - 2] + v[n - 1]);
    }
    if (n >= 3) {
        ans = min(ans, dp[n - 3] + v[n - 1] + v[n - 2]);
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