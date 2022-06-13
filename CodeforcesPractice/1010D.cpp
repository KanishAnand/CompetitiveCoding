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
vector<string> store;
vector<bool> v, vis, change;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
        }
    }

    if (store[a] == "AND") {
        v[a] = (v[adj[a][0]] & v[adj[a][1]]);
    } else if (store[a] == "OR") {
        v[a] = (v[adj[a][0]] | v[adj[a][1]]);
    } else if (store[a] == "XOR") {
        v[a] = (v[adj[a][0]] ^ v[adj[a][1]]);
    } else if (store[a] == "NOT") {
        v[a] = 1 - v[adj[a][0]];
    }
}

void dfs2(lli a) {
    lli p, q;
    if (store[a] == "AND") {
        p = v[adj[a][0]];
        q = v[adj[a][1]];

        if (p + q == 2) {
            change[adj[a][0]] = change[a];
            change[adj[a][1]] = change[a];
        } else if (p + q == 1) {
            if (p == 0) {
                change[adj[a][0]] = change[a];
            }
            if (q == 0) {
                change[adj[a][1]] = change[a];
            }
        }
    } else if (store[a] == "OR") {
        p = v[adj[a][0]];
        q = v[adj[a][1]];

        if (p + q == 0) {
            change[adj[a][0]] = change[a];
            change[adj[a][1]] = change[a];
        } else if (p + q == 1) {
            if (p == 1) {
                change[adj[a][0]] = change[a];
            }
            if (q == 1) {
                change[adj[a][1]] = change[a];
            }
        }
    } else if (store[a] == "XOR") {
        change[adj[a][0]] = change[a];
        change[adj[a][1]] = change[a];
    } else if (store[a] == "NOT") {
        change[adj[a][0]] = change[a];
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs2(val);
        }
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    string st;
    store.resize(n + 2);
    adj.resize(n + 2);
    v.resize(n + 2, 0);
    vector<lli> leafs;

    for (lli i = 1; i <= n; i++) {
        cin >> st;
        store[i] = st;
        if (st == "IN") {
            cin >> a;
            leafs.pb(i);
            v[i] = a;
        } else if (st == "NOT") {
            cin >> a;
            adj[i].pb(a);
        } else {
            cin >> a >> b;
            adj[i].pb(a);
            adj[i].pb(b);
        }
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    vis.clear();
    vis.resize(n + 2, 0);
    change.resize(n + 2, 0);
    vis[1] = 1;
    change[1] = 1;
    dfs2(1);

    lli ans = v[1];
    for (lli i = 0; i < leafs.size(); i++) {
        if (change[leafs[i]] == 1) {
            cout << 1 - ans;
        } else {
            cout << ans;
        }
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}