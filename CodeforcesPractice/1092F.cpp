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
vector<lli> v, subtree, level, ans;
vector<bool> vis;
vector<vector<lli>> adj;
lli ans1 = 0, tot = 0;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            level[val] = level[a] + 1;
            dfs(val);
            ans1 += (level[val] - 1) * v[val];
            subtree[a] += subtree[val];
        }
    }
    subtree[a] += v[a];
}

void dfs2(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            lli p = ans[a] - subtree[val] + (tot - subtree[val]);
            ans[val] = p;
            dfs2(val);
        }
    }
}

void solve() {
    lli n, a, b;
    cin >> n;

    adj.resize(n + 2);
    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        tot += a;
        v.pb(a);
    }

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    level.resize(n + 2, 0);
    subtree.resize(n + 2, 0);
    vis[1] = 1;
    level[1] = 1;
    dfs(1);

    vis.clear();
    vis.resize(n + 2, 0);
    ans.resize(n + 2, 0);
    ans[1] = ans1;
    vis[1] = 1;
    dfs2(1);

    lli finans = 0;
    for (lli i = 1; i <= n; i++) {
        finans = max(finans, ans[i]);
    }

    cout << finans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}