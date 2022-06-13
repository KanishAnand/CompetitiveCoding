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

void solve() {
    lli a, b;
    lli n, root, dist;
    vector<vector<lli>> adj, store_level;
    vector<lli> level;
    vector<bool> vis;
    cin >> n;
    adj.clear();
    store_level.clear();
    adj.resize(n + 2);
    store_level.resize(n + 2);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout << "? " << n << " ";
    for (lli i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
    cin >> root >> dist;

    queue<lli> qu;
    vis.clear();
    vis.resize(n + 2, 0);
    level.clear();
    level.resize(n + 2, 0);
    qu.push(root);
    vis[root] = 1;
    lli mx = -1;

    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (auto val : adj[a]) {
            if (!vis[val]) {
                vis[val] = 1;
                level[val] = level[a] + 1;
                mx = max(mx, level[val]);
                store_level[level[val]].pb(val);
                qu.push(val);
            }
        }
    }

    lli end = min(mx, dist);
    lli beg = end / 2 + end % 2;

    lli d;
    lli node1 = -1, node2 = -1;
    lli p = -1;
    // store_level[0].pb(root);

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        cout << "? " << store_level[mid].size() << " ";
        for (lli i = 0; i < store_level[mid].size(); i++) {
            cout << store_level[mid][i] << " ";
        }
        cout << endl;
        cin >> a >> d;
        if (d == dist) {
            if (mid > p) {
                p = mid;
                node1 = a;
            }
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    level.clear();
    level.resize(n + 2, 0);
    level[node1] = 0;
    vis.clear();
    vis.resize(n + 2, 0);
    vis[node1] = 1;
    qu.push(node1);
    vector<lli> query;

    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (auto val : adj[a]) {
            if (!vis[val]) {
                vis[val] = 1;
                level[val] = level[a] + 1;
                if (level[val] == dist) {
                    query.pb(val);
                }
                qu.push(val);
            }
        }
    }

    cout << "? " << query.size() << " ";
    for (lli i = 0; i < query.size(); i++) {
        cout << query[i] << " ";
    }
    cout << endl;
    cin >> node2 >> d;
    cout << "! " << node1 << " " << node2 << endl;
    string st;
    cin >> st;
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