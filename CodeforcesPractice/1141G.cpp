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

vector<vector<lli>> adj;
vector<lli> vis;
map<lli, map<lli, lli>> col, colrs;
vector<lli> ptr;
lli r;

lli dfs(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            while (ptr[a] <= r && col[a][ptr[a]] < 0) {
                ptr[a]++;
            }
            vis[val] = 1;
            colrs[a][val] = ptr[a];
            colrs[val][a] = ptr[a];
            col[a][ptr[a]]--;
            col[val][ptr[a]]--;
            if (ptr[a] != r) {
                ptr[a]++;
            }
            dfs(val);
        }
    }
}

void solve() {
    lli n, a, k, b;
    cin >> n >> k;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    ptr.resize(n + 2, 1);
    // colrs.resize(n + 2, vector<lli>(n + 2, 0));
    vector<pair<lli, lli>> edg;

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edg.pb({a, b});
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<lli> deg;
    for (lli i = 1; i <= n; i++) {
        deg.pb(adj[i].size());
    }
    sort(all(deg));

    r = deg[n - k - 1];
    // col.resize(n + 2, vector<lli>(r + 2, 1));
    for (lli i = 1; i <= n; i++) {
        col[i][r] = 1e6;
    }
    vis[1] = 1;
    dfs(1);

    cout << r << endl;
    for (lli i = 0; i < edg.size(); i++) {
        cout << colrs[edg[i].first][edg[i].second] << " ";
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