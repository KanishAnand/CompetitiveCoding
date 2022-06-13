#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli logn = 18;
vector<vector<lli>> dp, adj;
// dp[i][j] is the '2^j'th parent of i
vector<lli> vis, ht;
lli p = 0;

// storing 2^j th parent of i with dfs
lli dfs(lli a) {
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dp[val][0] = a;
            for (lli j = 1; j <= logn; j++) {
                dp[val][j] = dp[dp[val][j - 1]][j - 1];
            }
            ++p;
            ht[val] = p;
            dfs(val);
            --p;
        }
    }
    rt;
}

lli lca(lli a, lli b) {
    if (ht[a] != ht[b]) {
        if (ht[a] < ht[b]) {
            lli oa = a;
            a = b;
            b = oa;
        }
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

lli dist(lli a, lli b) {
    lli val = lca(a, b);
    return ht[a] + ht[b] - 2 * ht[val];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, q, b, c;
    vector<lli> v;
    cin >> n >> q;
    dp.resize(n + 2, vector<lli>(logn, 0));
    adj.resize(n + 2);

    fr(i, 0, n - 1) {
        cin >> a;
        adj[a].pb(i + 2);
        adj[i + 2].pb(a);
    }

    vis.resize(n + 2, 0);
    ht.resize(n + 2, 0);

    vis[1] = 1;
    dfs(1);
    while (q--) {
        cin >> a >> b >> c;
        lli mx, m;
        lli m1 = lca(a, b);
        lli m2 = lca(b, c);
        lli m3 = lca(a, c);
        if (m1 == m2) {
            m = m3;
        } else if (m1 == m3) {
            m = m2;
        } else {
            m = m1;
        }
        mx = max({dist(m, a), dist(m, b), dist(m, c)});
        // val = lca(a, b);
        // val1 = lca(val, c);
        // dis = ht[val] + ht[c] - 2 * ht[val1];
        // mx = max(mx, dis);
        // cout << dis << endl;

        // val = lca(b, c);
        // val1 = lca(val, a);
        // dis = ht[val] + ht[a] - 2 * ht[val1];
        // mx = max(mx, dis);
        // cout << dis << endl;

        // val = lca(a, c);
        // val1 = lca(val, b);
        // dis = ht[val] + ht[b] - 2 * ht[val1];
        // mx = max(mx, dis);
        // cout << dis << endl;

        cout << mx + 1 << endl;
    }

    rt;
}
