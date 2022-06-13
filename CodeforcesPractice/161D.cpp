#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli k;
double ans = 0;
vector<lli> vis;
vector<vector<lli>> dp;
vector<vector<lli>> adj;

lli dfs_dp(lli a) {
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs_dp(val);
            for (lli j = 1; j <= k; j++) {
                dp[a][j] += dp[val][j - 1];
            }
        }
    }
}

lli dfs(lli a) {
    ans += dp[a][k];
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            for (lli j = 1; j < k; j++) {
                double val1 = dp[val][j - 1];
                double val2 = dp[a][k - j] - dp[val][k - j - 1];
                ans += 0.5 * (val1 * val2);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b;
    cin >> n >> k;
    vis.resize(n + 2, 0);
    dp.resize(n + 2, vector<lli>(k + 2, 0));
    adj.resize(n + 2);
    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    fr(i, 0, n + 1) {
        dp[i][0] = 1;
    }

    vis[1] = 1;
    dfs_dp(1);
    // vis.resize(n + 2, 0);
    fr(i, 0, n + 2) {
        vis[i] = 0;
    }
    vis[1] = 1;
    dfs(1);
    cout << ans << endl;
    rt;
}