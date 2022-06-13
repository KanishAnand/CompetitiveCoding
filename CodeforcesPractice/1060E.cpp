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
vector<lli> subtree;
vector<bool> vis;
lli n, tot = 0;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subtree[a] += subtree[val];
        }
    }
    subtree[a]++;
    lli val = (n - subtree[a]) * subtree[a];
    tot += val;
}

void solve() {
    lli a, b;
    cin >> n;
    adj.resize(n + 2);
    subtree.resize(n + 2, 0);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    lli odd = 0;
    queue<lli> qu;
    vector<lli> level(n + 2, 0);
    vis.clear();
    vis.resize(n + 2, 0);
    vis[1] = 1;
    level[1] = 1;
    qu.push(1);
    odd++;

    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (auto val : adj[a]) {
            if (vis[val] == 0) {
                vis[val] = 1;
                qu.push(val);
                level[val] = level[a] + 1;
                if (level[val] % 2 == 1) {
                    odd++;
                }
            }
        }
    }

    lli odd_paths = odd * (n - odd);
    lli ans = (tot + odd_paths) / 2;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}
