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

vector<lli> v, dp;
vector<vector<pair<lli, lli>>> adj;
vector<bool> vis;
lli ans = 0;

void dfs(lli a) {
    vector<lli> tmp;
    for (auto val : adj[a]) {
        lli b = val.first;
        if (vis[b] == 1) {
            continue;
        }
        lli c = val.second;
        vis[b] = 1;
        dfs(b);
        if (dp[b] - c >= 0) {
            dp[a] = max(dp[a], dp[b] - c + v[a]);
            tmp.pb(dp[b] - c);
        }
    }

    ans = max(ans, dp[a]);
    sort(tmp.rbegin(), tmp.rend());
    if (tmp.size() >= 2) {
        ans = max(ans, tmp[0] + tmp[1] + v[a]);
    }
}

void solve() {
    lli n, a, b, c;
    cin >> n;
    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    adj.resize(n + 2);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    dp.resize(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        dp[i] = v[i];
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

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