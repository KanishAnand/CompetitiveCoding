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
vector<lli> vis;
lli n;

lli dfs_go(lli a, vector<vector<lli>> &adj, vector<vector<lli>> &trans,
           stack<lli> &topo) {
    if (adj[a].size() == 0) {
        vis[a] = 2;
        return a;
    }

    for (lli i = 0; i < adj[a].size(); i++) {
        if (vis[adj[a][i]] == 0) {
            vis[adj[a][i]] = 1;
            topo.push(dfs_go(adj[a][i], adj, trans, topo));
            vis[adj[a][i]] = 2;
        }
    }
    vis[a] = 2;
    return a;
}

lli dfs(vector<vector<lli>> &adj, vector<vector<lli>> &trans,
        stack<lli> &topo) {
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            topo.push(dfs_go(i, adj, trans, topo));
            vis[i] = 2;
        }
    }
    return 0;
}

lli dfs_go_trans(lli a, vector<vector<lli>> &adj, vector<vector<lli>> &trans,
                 stack<lli> &topo) {
    if (trans[a].size() == 0) {
        vis[a] = 2;
        return a;
    }

    for (int i = 0; i < trans[a].size(); i++) {
        if (vis[trans[a][i]] == 0) {
            vis[trans[a][i]] = 1;
            cout << dfs_go_trans(trans[a][i], adj, trans, topo) << " ";
            vis[trans[a][i]] = 2;
        }
    }
    vis[a] = 2;
    return a;
}

lli dfs_trans(vector<vector<lli>> &adj, vector<vector<lli>> &trans,
              stack<lli> &topo) {
    lli i, cnt = 1;
    while (cnt <= n) {
        if (vis[topo.top()] == 0) {
            i = topo.top();
            vis[i] = 1;
            cout << dfs_go_trans(i, adj, trans, topo) << " ";
            cout << endl;
            vis[i] = 2;
        }
        topo.pop();
        ++cnt;
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        lli a, b, m;
        cin >> n >> m;
        vector<vector<lli>> adj, trans;
        adj.resize(n + 2);
        trans.resize(n + 2);
        vis.resize(n + 2, 0);
        stack<lli> topo;

        fr(i, 0, m) {
            cin >> a >> b;
            adj[a].pb(b);
            trans[b].pb(a);
        }
        dfs(adj, trans, topo);
        for (lli i = 0; i < n + 1; i++) {
            vis[i] = 0;
        }

        dfs_trans(adj, trans, topo);
    }
    rt;
}
