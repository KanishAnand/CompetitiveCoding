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
vector<bool> vis;
vector<lli> king, rankk, level;
vector<vector<pair<lli, lli>>> adj;
vector<vector<lli>> dp, dp_max;

struct ed {
    lli u, v, w;
};

bool cmp(ed a, ed b) {
    return a.w < b.w;
}

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] > rankk[b]) {
        king[b] = king[a];
        rankk[a] += rankk[b];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val.first] == 0) {
            vis[val.first] = 1;
            level[val.first] = level[a] + 1;
            dp[val.first][0] = a;
            dp_max[val.first][0] = val.second;
            for (lli i = 1; i <= logn; i++) {
                dp[val.first][i] = dp[dp[val.first][i - 1]][i - 1];
                dp_max[val.first][i] = max(dp_max[val.first][i - 1],
                                           dp_max[dp[val.first][i - 1]][i - 1]);
            }
            // call
            dfs(val.first);
        }
    }
}

lli lca(lli a, lli b) {
    lli mx = 0;
    if (level[a] < level[b]) {
        swap(a, b);
    }

    if (level[a] != level[b]) {
        for (lli i = logn; i >= 0; i--) {
            if (dp[a][i] == 0) {
                continue;
            }
            lli val = dp[a][i];
            if (level[val] >= level[b]) {
                mx = max(mx, dp_max[a][i]);
                a = val;
            }
        }
    }

    if (a == b) {
        return mx;
    }

    for (lli i = logn; i >= 0; i--) {
        if (dp[a][i] == 0 || dp[b][i] == 0) {
            continue;
        }
        if (dp[a][i] != dp[b][i]) {
            mx = max(mx, dp_max[a][i]);
            mx = max(mx, dp_max[b][i]);
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    mx = max(mx, dp_max[a][0]);
    mx = max(mx, dp_max[b][0]);
    return mx;
    // return dp[a][0];
}

void solve() {
    lli n, a, m;
    cin >> n >> m;

    lli u, v, w;
    vector<ed> edges, edges_cp;
    for (lli i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    edges_cp = edges;

    sort(all(edges), cmp);
    lli ans = 0;

    king.resize(n + 2, 0);
    rankk.resize(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    level.resize(n + 2, 0);
    dp.resize(n + 2, vector<lli>(logn + 2, 0));
    dp_max.resize(n + 2, vector<lli>(logn + 2, 0));

    for (auto val : edges) {
        lli p = find(val.u);
        lli q = find(val.v);
        if (p != q) {
            ans += val.w;
            adj[val.v].pb({val.u, val.w});
            adj[val.u].pb({val.v, val.w});
            merge(p, q);
        }
    }

    vis[1] = 1;
    dfs(1);

    for (auto val : edges_cp) {
        lli mx = lca(val.u, val.v);
        lli an = ans - mx + val.w;
        cout << an << endl;
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