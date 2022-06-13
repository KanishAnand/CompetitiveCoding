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
vector<vector<lli>> adj;
vector<bool> vis;
vector<lli> subcost, v;
vector<vector<lli>> storemax;
lli ans = -1e12;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subcost[a] += subcost[val];
            lli p = subcost[val], q = -1e12;
            if (storemax[val].size() != 0) {
                q = storemax[val][0];
            }
            storemax[a].pb(max(q, p));
        }
    }

    subcost[a] += v[a];
    sort(storemax[a].rbegin(), storemax[a].rend());
    if (storemax[a].size() >= 2) {
        ans = max(ans, storemax[a][0] + storemax[a][1]);
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    adj.resize(n + 2);
    storemax.resize(n + 2);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    subcost.resize(n + 2, 0);

    vis[1] = 1;
    dfs(1);

    if (ans == -1e12) {
        cout << "Impossible" << endl;
        return;
    }
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