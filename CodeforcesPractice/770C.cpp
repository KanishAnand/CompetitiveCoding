#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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
vector<bool> v;
vector<lli> vis;
vector<vector<lli>> adj;
vector<lli> topo;
bool cycle = 0;

void dfs(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            vis[val] = 2;
            topo.pb(val);
        } else if (vis[val] == 1) {
            cycle = 1;
            return;
        }
    }
}

void solve() {
    lli n, a, k, no;
    cin >> n >> k;
    vis.resize(n + 2, 0);
    v.resize(n + 2, 0);
    adj.resize(n + 2);

    for (lli i = 0; i < k; i++) {
        cin >> a;
        v[a] = 1;
    }

    for (lli i = 1; i <= n; i++) {
        cin >> no;
        for (lli j = 0; j < no; j++) {
            cin >> a;
            adj[i].pb(a);
        }
    }

    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0 && v[i] == 1) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 2;
            topo.pb(i);
        }
    }

    if (cycle == 1) {
        cout << "-1" << endln;
    } else {
        cout << topo.size() << endl;
        for (lli i = 0; i < topo.size(); i++) {
            cout << topo[i] << " ";
        }
        cout << endln;
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