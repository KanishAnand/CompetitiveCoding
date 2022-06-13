#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

lli n;
vector<lli> topo;
vector<lli> vis;
vector<vector<lli>> adj;

lli dfs_go(lli val) {
    for (lli i = 0; i < adj[val].size(); i++) {
        if (vis[adj[val][i]] == 0) {
            vis[adj[val][i]] = 1;
            dfs_go(adj[val][i]);
            topo.pb(adj[val][i]);
        }
    }
}

lli dfs() {
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs_go(i);
            topo.pb(i);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a, m, b;
    cin >> n >> m;
    vis.resize(n + 2, 0);
    adj.resize(n + 2);
    fr(i, 0, m) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    vector<lli> dis(n + 2, 0);
    dfs();
    reverse(all(topo));

    for (lli i = 0; i < topo.size(); i++) {
        for (lli j = 0; j < adj[topo[i]].size(); j++) {
            dis[adj[topo[i]][j]] = max(dis[topo[i]] + 1, dis[adj[topo[i]][j]]);
        }
    }

    lli ans = -1;
    for (lli i = 1; i <= n; i++) {
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
    rt;
}