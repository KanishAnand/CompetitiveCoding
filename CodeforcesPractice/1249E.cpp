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
    lli n, a, c;
    cin >> n >> c;
    vector<lli> va, vb;
    for (lli i = 0; i < n - 1; i++) {
        cin >> a;
        va.pb(a);
    }
    for (lli i = 0; i < n - 1; i++) {
        cin >> a;
        vb.pb(a);
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(2, 0));
    dp[1][0] = va[0];
    dp[1][1] = vb[0] + c;
    for (lli i = 2; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + va[i - 1];
        dp[i][1] = min(dp[i - 1][0] + vb[i - 1] + c, dp[i - 1][1] + vb[i - 1]);
    }

    for (lli i = 0; i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}