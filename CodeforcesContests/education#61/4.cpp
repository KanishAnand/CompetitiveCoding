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

lli fun(lli n, string st) {
    vector<vector<lli>> dp(n + 3, vector<lli>(n + 3, 1000));

    for (lli i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (lli len = 2; len <= n; len++) {
        for (lli i = 0; i < n - len + 1; i++) {
            lli l = i, r = i + len - 1;
            lli val4 = dp[l + 1][r];
            if (l + 1 > r) {
                val4 = 0;
            }
            dp[l][r] = min(dp[l][r], 1 + val4);

            for (lli j = l + 1; j <= r; j++) {
                if (st[j] == st[l]) {
                    lli val1 = dp[l + 1][j - 1];
                    if (l + 1 > j - 1) {
                        val1 = 0;
                    }
                    lli val2 = dp[j][r];
                    if (j > r) {
                        val2 = 0;
                    }

                    lli val = val1 + val2;
                    dp[l][r] = min(dp[l][r], val);
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}

void solve() {
    lli a, n;
    cin >> n;
    string st;
    cin >> st;
    fun(n, st);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}