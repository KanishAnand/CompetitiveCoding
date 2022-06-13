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

vector<lli> vis, mark, subtree;
vector<vector<lli>> adj;

void dfs(lli a, lli &s, lli &d) {
    if (a == d) {
        mark[a] = -1;
        return;
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val, s, d);

            if (a != s && mark[val] == -1) {
                mark[a] = -1;
            } else if (mark[val] != -1) {
                subtree[a] += subtree[val];
            }
        } else {
            if (a != s && mark[val] == -1) {
                mark[a] = -1;
            }
        }
    }

    if (a != s) {
        subtree[a]++;
    }
    if (mark[a] == -1) {
        subtree[a] = 0;
    }
}

void solve() {
    adj.clear();
    vis.clear();
    mark.clear();
    subtree.clear();

    lli n, m, src, des;
    cin >> n >> m >> src >> des;
    adj.resize(n + 2);

    lli x, y;
    for (lli i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vis.resize(n + 2, 0);
    mark.resize(n + 2, 0);
    subtree.resize(n + 2, 0);
    vis[src] = 1;
    dfs(src, src, des);
    lli cntsrc = subtree[src];
    // cout << cntsrc << endl;

    vis.clear();
    mark.clear();
    subtree.clear();
    vis.resize(n + 2, 0);
    mark.resize(n + 2, 0);
    subtree.resize(n + 2, 0);
    vis[des] = 1;
    dfs(des, des, src);

    lli cntdes = subtree[des];

    // cout << cntsrc << " " << cntdes << endl;
    lli ans = cntsrc * cntdes;
    cout << ans << endl;
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