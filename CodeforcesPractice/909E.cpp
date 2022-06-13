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
const double PI = 3.14159265358979323846264338;
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

vector<vector<lli>> adj;
vector<lli> vis, v, dp;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            vis[val] = 2;
            if (v[a] == 0 && v[val] == 1) {
                dp[a] = max(dp[a], dp[val] + 1);
            } else {
                dp[a] = max(dp[a], dp[val]);
            }
        } else if (vis[val] == 2) {
            if (v[a] == 0 && v[val] == 1) {
                dp[a] = max(dp[a], dp[val] + 1);
            } else {
                dp[a] = max(dp[a], dp[val]);
            }
        }
    }

    if (adj[a].size() == 0 && v[a] == 0) {
        dp[a] = 1;
    }
}

void solve() {
    lli n, a, m, b;
    cin >> n >> m;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    dp.resize(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(1 - a);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    for (lli i = 0; i < n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 2;
        }
    }

    lli ans = -1;
    for (lli i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
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