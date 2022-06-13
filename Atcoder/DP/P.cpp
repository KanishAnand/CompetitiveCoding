#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli n, mod = 1e9 + 7;
vector<lli> vis;
vector<vector<lli>> adj, dp;

lli dfs(lli a) {
    int flag = 0;
    for (lli i = 0; i < adj[a].size(); i++) {
        if (vis[adj[a][i]] == 0) {
            flag = 1;
            vis[adj[a][i]] = 1;
            dfs(adj[a][i]);
            dp[a][0] *= (dp[adj[a][i]][0] + dp[adj[a][i]][1]);
            dp[a][1] *= dp[adj[a][i]][0];
            dp[a][0] %= mod;
            dp[a][1] %= mod;
        }
    }
    if (flag == 0) {
        dp[a][0] = 1;
        dp[a][1] = 1;
    }

    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a, b;
    cin >> n;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    dp.resize(n + 2, vector<lli>(2, 1));

    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis[1] = 1;
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % mod << endl;
    rt;
}