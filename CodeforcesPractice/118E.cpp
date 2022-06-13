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
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

lli isBridge = 0, timer = 0;
vector<lli> vis, tin, low;
vector<vector<lli>> adj;
vector<pair<lli, lli>> ans;

void dfs(lli a, lli par = -1) {
    tin[a] = low[a] = timer++;

    for (lli val : adj[a]) {
        if (val == par) continue;

        if (vis[val] != 2) {
            ans.pb({a, val});
        }

        if (vis[val]) {
            low[a] = min(low[a], tin[val]);
        } else {
            vis[val] = 1;
            dfs(val, a);
            low[a] = min(low[a], low[val]);
            if (low[val] > tin[a]) {
                isBridge = 1;
            }
        }
    }

    vis[a] = 2;
}

void solve() {
    lli n, m, a, b;
    cin >> n >> m;

    vis.resize(n + 2, 0);
    tin.resize(n + 2, -1);
    low.resize(n + 2, -1);
    adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis[1] = 1;
    dfs(1);

    if (isBridge) {
        cout << 0 << endl;
        return;
    }

    for (auto edg : ans) {
        cout << edg.first << " " << edg.second << endln;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}