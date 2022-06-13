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
vector<lli> vis, no;
vector<vector<lli>> adj;
vector<set<lli>> store;
vector<lli> v;
lli cnt = 0;

lli dfs(lli a) {
    store[cnt].insert(v[a]);
    no[a] = cnt;
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
        }
    }
}

void solve() {
    lli n, a, m, b;
    cin >> n >> m;
    no.resize(n + 2, -1);
    vis.resize(n + 2, 0);
    adj.resize(n + 2);
    store.resize(n + 2);
    v.pb(0);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            cnt++;
        }
    }

    for (lli i = 1; i <= n; i++) {
        lli val = no[i];
        auto it = store[val].end();
        it--;
        cout << *it << " ";
        store[val].erase(it);
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}