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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
lli n, m, ans = -1e10;
stack<lli> topo;
vector<lli> v, vis, dp_max;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            topo.push(val);
        }
    }
}

void dfs2(lli a, lli mn) {
    mn = min(mn, v[a]);
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs2(val, mn);
        }
        dp_max[a] = max(dp_max[a], dp_max[val]);
    }

    if (sz(adj[a]) != 0) {
        ans = max(ans, dp_max[a] - mn);
    }
    dp_max[a] = max(dp_max[a], v[a]);
}

void solve() {
    lli a;
    cin >> n >> m;
    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli x, y;
    adj.resize(n + 2);
    for (lli i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].pb(y);
    }

    vis.resize(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            topo.push(i);
        }
    }

    vis.clear();
    vis.resize(n + 2, 0);
    dp_max.resize(n + 2, 0);

    vector<lli> tmp;
    while (!topo.empty()) {
        lli el = topo.top();
        tmp.pb(el);
        topo.pop();
    }
    reverse(all(tmp));

    for (auto el : tmp) {
        // cout << el << " a" << endl;
        if (vis[el] == 0) {
            vis[el] = 1;
            dfs2(el, 1e10);
        }
        // cout << ans << endl;
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