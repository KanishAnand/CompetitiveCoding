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
    lli n, a, l, b;
    cin >> n >> l;
    vector<pair<lli, lli>> store;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        store.pb({a, b});
    }

    // dp : sum, index, width of this
    vector<vector<vector<lli>>> dp(
        l + 2, vector<vector<lli>>(n + 2, vector<lli>(102, 0)));

    for (lli i = 0; i < n; i++) {
        a = store[i].first;
        b = store[i].second;
        if (a != b) {
            if (a <= l) {
                dp[a][i][b]++;
            }
            if (b <= l) {
                dp[b][i][a]++;
            }
        } else {
            if (a <= l) {
                dp[a][i][a]++;
            }
        }
    }

    for (lli i = 1; i <= l; i++) {
        for (lli j = 0; j < n; j++) {
            a = store[j].first;
            b = store[j].second;
            for (lli k = 0; k < n; k++) {
                if (k == j) {
                    continue;
                }
                lli val = i - a;
                if (val > 0) {
                    dp[i][j][b] += dp[val][k][a];
                    dp[i][j][b] %= MOD;
                }
                if (b != a) {
                    val = i - b;
                    if (val > 0) {
                        dp[i][j][a] += dp[val][k][b];
                        dp[i][j][a] %= MOD;
                    }
                }
            }
        }
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        a = store[i].first;
        b = store[i].second;
        ans += dp[l][i][a];
        ans %= MOD;
        if (a != b) {
            ans += dp[l][i][b];
            ans %= MOD;
        }
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}