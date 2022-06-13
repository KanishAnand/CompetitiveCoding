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
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    sort(all(v));
    vector<lli> st(n + 1);

    for (lli i = 0; i < n; i++) {
        for (lli j = i; j >= 0; j--) {
            if (v[i] - v[j] <= 5) {
                st[i] = j;
            } else {
                break;
            }
        }
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(k + 2, 0));
    dp[0][1] = 1;

    for (lli i = 1; i < n; i++) {
        for (lli j = 1; j <= k; j++) {
            lli val = st[i] - 1;
            lli nm = i - st[i] + 1;
            if (val >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[val][j - 1] + nm);
            } else {
                dp[i][j] = max(dp[i - 1][j], nm);
            }
        }
    }

    lli ans = -1;
    for (lli i = 0; i <= k; i++) {
        ans = max(ans, dp[n - 1][i]);
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