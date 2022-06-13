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

// vector<lli> vis;
// vector<lli> cnt;

// lli dfs(lli a) {
//     for (int i = 0; i < adj[a].size(); i++) {
//         lli val = adj[a][i];
//         if (vis[val] == 0) {
//             vis[val] = 1;
//             dfs(val);
//             cnt[a] += cnt[val];
//         }
//     }
//     cnt[a]++;
// }

void solve() {
    lli n, a, root, b;
    cin >> n >> root;
    // vis.empty();
    // cnt.empty();
    vector<vector<lli>> adj;
    // adj.empty();
    // vis.resize(n + 2, 0);
    // cnt.resize(n + 2, 0);
    adj.resize(n + 2);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (adj[root].size() <= 1) {
        cout << "Ayush" << endl;
        return;
    }

    // vis[root] = 1;
    // dfs(root);

    // lli ans = 0;

    // for (int i = 0; i < adj[root].size(); i++) {
    //     lli val = adj[root][i];
    //     ans += cnt[val];
    // }

    lli ans = n - 1;

    if (ans % 2 == 1) {
        cout << "Ayush" << endl;
    } else {
        cout << "Ashish" << endl;
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