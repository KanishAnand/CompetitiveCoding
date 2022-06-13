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

bool cycle = 0;
stack<lli> topo;
vector<lli> vis;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            vis[val] = 2;
            topo.push(val);
        } else if (vis[val] == 1) {
            cycle = 1;
            return;
        }
    }
}

void solve() {
    lli n, a, m, b;
    cin >> n >> m;
    adj.clear();
    vis.clear();
    cycle = 0;
    adj.resize(n + 2);
    vis.resize(n + 2);
    vector<pair<lli, lli>> store, store2;

    while (!topo.empty()) {
        topo.pop();
    }

    lli t, x, y;
    for (lli i = 0; i < m; i++) {
        cin >> t >> x >> y;
        if (t == 1) {
            adj[x].pb(y);
            store2.pb({x, y});
        } else {
            store.pb({x, y});
        }
    }

    lli beg = 0;
    vector<lli> tim(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 2;
            topo.push(i);
            if (cycle == 1) {
                cout << "NO" << endln;
                return;
            }
        }
    }

    while (!topo.empty()) {
        a = topo.top();
        topo.pop();
        beg++;
        tim[a] = beg;
    }

    for (lli i = 0; i < sz(store); i++) {
        a = store[i].first;
        b = store[i].second;
        // if (tim[a] != 0 && tim[b] != 0) {
        if (tim[a] < tim[b]) {
            store2.pb({a, b});
        } else {
            store2.pb({b, a});
        }
        // } else if (tim[a] == 0 && tim[b] != 0) {
        //     store2.pb({b, a});
        // } else if (tim[a] != 0 && tim[b] == 0) {
        //     store2.pb({a, b});
        // } else {
        //     rem.pb({a, b});
        // }
    }

    cout << "YES" << endln;
    for (auto val : store2) {
        cout << val.first << " " << val.second << endln;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}