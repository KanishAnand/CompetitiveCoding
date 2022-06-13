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
vector<lli> temp, vis, subtree, ans;
lli tot = 0, root;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subtree[a] += subtree[val];
        }
    }

    subtree[a] += temp[a];
    if (a != root && subtree[a] == tot && ans.size() != 2) {
        subtree[a] = 0;
        ans.pb(a);
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    temp.pb(0);
    adj.resize(n + 2);
    subtree.resize(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        cin >> a >> b;
        tot += b;
        temp.pb(b);
        if (a == 0) {
            root = i;
        } else {
            adj[a].pb(i);
        }
    }

    if (tot % 3 != 0) {
        cout << "-1" << endl;
        return;
    }

    tot /= 3;
    vis.resize(n + 2, 0);
    vis[root] = 1;
    dfs(root);

    if (ans.size() != 2) {
        cout << "-1" << endl;
    } else {
        cout << ans[0] << " " << ans[1] << endl;
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