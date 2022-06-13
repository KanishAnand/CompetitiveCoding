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

lli mx = 0;
vector<lli> vis, dis;
vector<vector<lli>> adj;

lli dfs(lli a) {
    lli leaf = 1;

    vector<lli> v;
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            leaf = 0;
            vis[val] = 1;
            v.pb(dfs(val));
        }
    }

    if (leaf == 1) {
        return 0;
    } else {
        sort(all(v));
        reverse(all(v));
        mx = max(mx, v[0] + 1);
        if (sz(v) >= 2) {
            mx = max(mx, v[0] + v[1] + 2);
        }
        return v[0] + 1;
    }
}

void dfs_1(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dis[val] = dis[a] + 1;
            dfs_1(val);
        }
    }
}

void solve() {
    mx = 0;
    lli n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;

    adj.clear();
    adj.resize(n + 2);

    lli aa, bb;
    for (lli i = 0; i < n - 1; i++) {
        cin >> aa >> bb;
        adj[aa].pb(bb);
        adj[bb].pb(aa);
    }

    vis.clear();
    vis.resize(n + 2, 0);
    vis[a] = 1;
    dis.clear();
    dis.resize(n + 2, 0);
    dfs_1(a);

    if (dis[b] <= da) {
        cout << "Alice" << endl;
        return;
    }

    vis.clear();
    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    if (mx > 2 * da && db > 2 * da) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
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