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

lli logn = 18;

map<lli, map<lli, lli>> ans;
vector<lli> vis, subtree, ht;
// dp[i][j] is the '2^j'th parent of i
vector<vector<lli>> adj, dp;

// storing 2^j th parent of i with dfs
void dfs_dp(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dp[val][0] = a;
            // call this before dfs call
            for (lli j = 1; j <= logn; j++) {
                dp[val][j] = dp[dp[val][j - 1]][j - 1];
            }
            ht[val] = ht[a] + 1;
            dfs_dp(val);
        }
    }
}

lli lca(lli a, lli b) {
    if (ht[a] < ht[b]) {
        swap(a, b);
    }

    if (ht[a] != ht[b]) {
        for (lli i = logn; i >= 0; i--) {
            if (dp[a][i] == 0) {
                continue;
            }
            lli val = dp[a][i];
            if (ht[val] >= ht[b]) {
                a = val;
            }
        }
    }

    if (a == b) {
        return a;
    }

    for (lli i = logn; i >= 0; i--) {
        if (dp[a][i] == 0 || dp[b][i] == 0) {
            continue;
        }
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subtree[a] += subtree[val];
            ans[a][val] = subtree[val];
            ans[val][a] = subtree[val];
        }
    }
}

void solve() {
    lli n, a, b, k;
    cin >> n;
    adj.resize(n + 2);

    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v.pb({a, b});
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dp.resize(n + 2, vector<lli>(logn + 2, 0));
    ht.resize(n + 2, 0);
    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs_dp(1);

    cin >> k;
    subtree.resize(n + 2, 0);

    for (lli i = 0; i < k; i++) {
        cin >> a >> b;
        lli val = lca(a, b);
        if (val == a) {
            subtree[b]++;
            subtree[a]--;
        } else if (val == b) {
            subtree[b]--;
            subtree[a]++;
        } else {
            subtree[b]++;
            subtree[a]++;
            subtree[val] -= 2;
        }
    }

    vis.clear();
    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    for (lli i = 0; i < n - 1; i++) {
        cout << ans[v[i].first][v[i].second] << " ";
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