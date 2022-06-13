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
vector<lli> sum, ans, par;

void dfs(lli a, lli flag) {
    lli mn = 1e10;
    for (auto val : adj[a]) {
        dfs(val, 1 - flag);
        mn = min(mn, sum[val] - sum[par[a]]);
    }

    if (!flag) {
        if (mn == 1e10) {
            mn = 0;
        }
        ans[a] = mn;
        for (auto val : adj[a]) {
            ans[val] = sum[val] - sum[par[a]] - mn;
        }
    }
}

void solve() {
    lli n, a;
    cin >> n;
    adj.resize(n + 2);
    par.resize(n + 2);

    for (lli i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
        par[i] = a;
    }

    sum.pb(0);
    for (lli i = 1; i <= n; i++) {
        cin >> a;
        sum.pb(a);
    }

    ans.resize(n + 2, 0);
    ans[1] = sum[1];
    dfs(1, 1);

    lli fin = 0;
    for (lli i = 1; i <= n; i++) {
        if (ans[i] < 0) {
            cout << "-1" << endl;
            return;
        }
        fin += ans[i];
    }

    cout << fin << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}