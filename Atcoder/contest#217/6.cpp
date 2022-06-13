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
const lli MOD = 998244353;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

int dp[402][402];

void solve() {
    int n, m;
    cin >> n >> m;
    n *= 2;

    int a, b;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        if (a > b) {
            swap(a, b);
        }
        v.pb({a, b});
    }

    for (int len = 2; len <= n; len += 2) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len - 1, tot = 0;
            for (auto pr : v) {
                if (pr.first >= start && pr.second <= end) {
                    int len1 = pr.first - start, len2 = (pr.second - 1) - (pr.first + 1) + 1, len3 = end - pr.second;
                    if (((len1 % 2) + (len2 % 2) + (len3 % 2)) != 0) {
                        continue;
                    }

                    // cout << start << " A " << end << endl;
                    // cout << pr.first << " B " << pr.second << endl;
                    // cout << len1 << " " << len2 << " " << len3 << endl;
                    lli p = 1;
                    if (len1 > 0) {
                        // p *= (len1 / 2);
                        // p %= MOD;
                        p *= dp[start][pr.first - 1];
                        p %= MOD;
                    }
                    if (len2 > 0) {
                        // p *= (len2 / 2);
                        // p %= MOD;
                        p *= dp[pr.first + 1][pr.second - 1];
                        p %= MOD;
                    }
                    if (len3 > 0) {
                        // p *= (len3 / 2);
                        // p %= MOD;
                        p *= dp[pr.second + 1][end];
                        p %= MOD;
                    }
                    // cout << p << endl;
                    tot += p;
                    tot %= MOD;
                }
            }

            dp[start][end] = tot;
        }
    }

    int ans = dp[0][n - 1];
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