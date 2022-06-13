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
    lli n, a, m, k, x, y;
    cin >> n >> m >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    vector<vector<lli>> arr(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 0; i < k; i++) {
        cin >> x >> y >> a;
        x--, y--;
        arr[x][y] = a;
    }

    vector<vector<lli>> dp(pow(2, n), vector<lli>(n, 0));

    for (lli bit = 0; bit < n; bit++) {
        dp[(1 << bit)][bit] = v[bit];
    }

    for (lli mask = 0; mask < pow(2, n); mask++) {
        for (lli bit = 0; bit < n; bit++) {
            if ((mask & (1 << bit)) != 0) {
                for (lli zerobit = 0; zerobit < n; zerobit++) {
                    if ((mask & (1 << zerobit)) == 0) {
                        dp[(mask | (1 << zerobit))][zerobit] =
                            max(dp[(mask | (1 << zerobit))][zerobit],
                                dp[mask][bit] + arr[bit][zerobit] + v[zerobit]);
                    }
                }
            }
        }
    }

    lli ans = 0;
    for (lli mask = 0; mask < pow(2, n); mask++) {
        lli cnt = 0;
        for (lli bit = 0; bit < n; bit++) {
            if (((1 << bit) & mask) != 0) {
                cnt++;
            }
        }
        if (cnt == m) {
            for (lli pos = 0; pos < n; pos++) {
                ans = max(ans, dp[mask][pos]);
            }
        }
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