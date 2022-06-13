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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2));
    vector<lli> pref(n + 2);

    for (lli i = 0; i < n; i++) {
        dp[i][i] = v[i];
        pref[i] = v[i];
        if (i != 0) {
            pref[i] += pref[i - 1];
        }
    }

    for (lli len = 2; len <= n; len++) {
        for (lli i = 0; i <= n - len; i++) {
            lli j = i + len - 1;
            lli sum1 = pref[j] - pref[i + 1] + v[i + 1];
            lli sum2 = pref[j - 1] - pref[i] + v[i];
            lli val1 = v[i] + sum1 - dp[i + 1][j];
            lli val2 = v[j] + sum2 - dp[i][j - 1];
            dp[i][j] = max(val1, val2);
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}