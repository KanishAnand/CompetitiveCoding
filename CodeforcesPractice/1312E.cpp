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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 0; i < n; i++) {
        dp[i][i] = v[i];
    }

    for (lli i = 2; i <= n; i++) {
        for (lli j = 0; j < n - i + 1; j++) {
            lli l = j, r = j + i - 1;
            for (lli k = l; k < r; k++) {
                if (dp[l][k] == dp[k + 1][r] && dp[l][k] != 0) {
                    dp[l][r] = dp[l][k] + 1;
                }
            }
        }
    }

    vector<lli> dp2(n + 1, 1000);

    dp2[0] = 1;

    for (lli i = 1; i < n; i++) {
        for (lli j = i; j >= 0; j--) {
            if (dp[j][i] != 0) {
                // if (j != 0) {
                dp2[i] = min(dp2[i], dp2[j - 1] + 1);
                // } else {
                //     dp2[i] = 1;
                // }
            }
        }
    }

    cout << dp2[n - 1] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}