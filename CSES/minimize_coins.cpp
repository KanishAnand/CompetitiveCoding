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
    lli n, a, x;
    cin >> n >> x;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli INF = x + 2;
    vector<lli> dp(x + 2, INF);
    dp[0] = 0;

    for (lli i = 1; i <= x; i++) {
        for (lli j = 0; j < n; j++) {
            if (i - v[j] >= 0) {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    if (dp[x] == INF) {
        dp[x] = -1;
    }
    cout << dp[x] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}