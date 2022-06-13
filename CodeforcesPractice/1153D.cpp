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
vector<lli> v, ans;
vector<vector<lli>> adj;
lli leaves = 0;

void dfs(lli a) {
    if (adj[a].size() == 0) {
        ans[a] = 1;
        leaves++;
        return;
    }

    lli mn = 1e10, sum = 0;
    for (auto val : adj[a]) {
        dfs(val);
        mn = min(mn, ans[val]);
        sum += ans[val];
    }

    if (v[a] == 0) {
        ans[a] = sum;
    } else {
        ans[a] = mn;
    }
}

void solve() {
    lli n, a;
    cin >> n;
    ans.resize(n + 2, 0);
    adj.resize(n + 2);

    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (lli i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
    }

    dfs(1);
    cout << leaves - ans[1] + 1 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}