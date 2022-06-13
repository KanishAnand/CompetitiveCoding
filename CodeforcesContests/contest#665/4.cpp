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

lli n;
vector<lli> vis, subtree, store;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subtree[a] += subtree[val];
        }
    }
    subtree[a]++;
    lli p = subtree[a] * (n - subtree[a]);
    if (p != 0) {
        store.pb(p);
    }
}

void solve() {
    lli a, m, b;
    cin >> n;

    adj.clear();
    vis.clear();
    store.clear();
    subtree.clear();

    adj.resize(n + 2);
    subtree.resize(n + 2, 0);
    vis.resize(n + 2, 0);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cin >> m;
    vector<lli> factors;
    for (lli i = 0; i < m; i++) {
        cin >> a;
        factors.pb(a);
    }

    vis[1] = 1;
    dfs(1);

    for (lli i = 0; i < n - 1 - m; i++) {
        factors.pb(1);
    }

    sort(factors.rbegin(), factors.rend());

    sort(all(store));
    reverse(all(store));

    lli no = factors.size() - (n - 1);
    lli rem = 1;
    for (lli i = 0; i < no; i++) {
        rem *= factors[i];
        rem %= MOD;
    }

    lli ans = 0, f = 0;
    for (lli i = 0; i < store.size(); i++) {
        if (f == 0) {
            f = 1;
            rem *= factors[no];
            rem %= MOD;
            ans += (store[i] * rem) % MOD;
            ans %= MOD;
        } else {
            ans += (store[i] * factors[no]) % MOD;
            ans %= MOD;
        }
        no++;
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}