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

lli n, m;
vector<vector<pair<lli, lli>>> adj, rev_adj;
vector<lli> topo;
vector<bool> vis;

void dfs(lli a) {
    for (auto val : adj[a]) {
        lli v = val.first;
        if (vis[v] == 0) {
            vis[v] = 1;
            dfs(v);
            topo.pb(v);
        }
    }
}

void solve() {
    lli a, b;
    cin >> n >> m;
    adj.resize(n + 2);
    rev_adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb({b, i + 1});
        rev_adj[b].pb({a, i + 1});
    }

    vis.resize(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            topo.pb(i);
        }
    }

    vector<lli> dp(n + 2, 0), res(n + 2, 0);
    lli val = 0;

    for (lli i = 0; i < topo.size(); i++) {
        a = topo[i];
        if (dp[a] == n - 1) {
            cout << res[a] << endl;
            return;
        }
        for (auto v : rev_adj[a]) {
            lli p = v.first;
            lli q = v.second;
            if (dp[a] + 1 > dp[p]) {
                dp[p] = dp[a] + 1;
                res[p] = max(res[a], q);
            }
        }
    }

    cout << "-1" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}