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

vector<vector<lli>> adj;
vector<lli> vis;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
        }
    }
}

void dfs2(lli a, vector<lli> &tmp) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            tmp.pb(val);
            vis[val] = 1;
            dfs2(val, tmp);
        }
    }
}

void solve() {
    lli n, a, m, root, b;
    cin >> n >> m >> root;
    adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    vis.resize(n + 2, 0);
    vis[root] = 1;
    dfs(root);

    vector<lli> v;
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            v.pb(i);
        }
    }

    vector<pair<lli, vector<lli>>> store;

    for (lli i = 0; i < sz(v); i++) {
        vector<lli> tmp;
        tmp.pb(v[i]);
        vis[v[i]] = 1;
        dfs2(v[i], tmp);
        store.pb({sz(tmp), tmp});
        for (lli j = 0; j < sz(tmp); j++) {
            vis[tmp[j]] = 0;
        }
    }

    sort(store.rbegin(), store.rend());
    lli ans = 0;

    for (lli i = 0; i < sz(store); i++) {
        v = store[i].second;
        if (vis[v[0]] == 1) {
            continue;
        }
        for (lli j = 0; j < sz(v); j++) {
            vis[v[j]] = 1;
        }
        ans++;
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