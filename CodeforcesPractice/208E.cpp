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

lli logn = 18, tmm = 1;
vector<bool> vis;
vector<lli> level, start, finish;
vector<vector<lli>> adj, dp, store;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            level[val] = level[a] + 1;
            start[val] = tmm;
            tmm++;
            store[level[val]].pb(start[val]);
            dp[val][0] = a;
            for (lli j = 1; j <= logn; j++) {
                dp[val][j] = dp[dp[val][j - 1]][j - 1];
            }
            dfs(val);
            finish[val] = tmm;
            tmm++;
        }
    }
}

lli find_pthparent(lli v, lli p) {
    for (lli i = logn; i >= 0; i--) {
        lli val = pow(2, i);
        if (p < val) {
            continue;
        }
        p -= val;
        v = dp[v][i];
    }
    return v;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> roots;
    adj.resize(n + 2);
    store.resize(n + 2);
    start.resize(n + 2, 0);
    finish.resize(n + 2, 0);
    level.resize(n + 2, 0);
    dp.resize(n + 2, vector<lli>(logn + 2, 0));

    for (lli i = 1; i <= n; i++) {
        cin >> a;
        if (a) {
            adj[a].pb(i);
        } else {
            roots.pb(i);
        }
    }

    vis.resize(n + 2, 0);

    for (auto rot : roots) {
        vis[rot] = 1;
        level[rot] = 1;
        start[rot] = tmm;
        tmm++;
        store[1].pb(start[rot]);
        dfs(rot);
        finish[rot] = tmm;
        tmm++;
    }

    lli q, v, p;
    cin >> q;
    while (q--) {
        cin >> v >> p;
        lli lvl = level[v];
        lli par = find_pthparent(v, p);
        if (par == 0) {
            cout << "0 ";
            continue;
        }

        auto it1 =
            lower_bound(store[lvl].begin(), store[lvl].end(), start[par]);
        lli ind1 = it1 - store[lvl].begin();
        auto it2 =
            lower_bound(store[lvl].begin(), store[lvl].end(), finish[par]);
        lli ind2 = it2 - store[lvl].begin();
        lli an = ind2 - ind1;
        an--;
        cout << an << " ";
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