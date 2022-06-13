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
vector<lli> v, vis, ans;
vector<vector<lli>> adj, store;

void dfs(lli a, lli par, lli cnt, vector<lli> &mp) {
    for (auto val : store[v[a]]) {
        mp[val]++;
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val, a, cnt + 1, mp);
        }
    }

    for (auto val : store[v[a]]) {
        if (mp[val] >= cnt - 1) {
            ans[a] = max(ans[a], val);
        }
        mp[val]--;
    }

    if (par != 0) {
        for (auto val : store[v[par]]) {
            if (mp[val] >= cnt - 1) {
                ans[a] = max(ans[a], val);
            }
        }
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    v.pb(0);
    lli mx = -1;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mx = max(mx, a);
        v.pb(a);
    }

    store.resize(mx + 3);
    for (lli i = 2; i <= mx; i++) {
        for (lli j = i; j <= mx; j += i) {
            store[j].pb(i);
        }
    }

    adj.resize(n + 2);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    ans.resize(n + 2, 1);
    vis.resize(n + 2, 0);
    vector<lli> mp(mx + 2, 0);
    vis[1] = 1;
    dfs(1, 0, 1, mp);

    for (lli i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}