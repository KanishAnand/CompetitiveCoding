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
#define len(x) (lli)(x.length())
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

vector<lli> valu, leaves;
vector<vector<lli>> adj;

pair<lli, lli> dfs(lli a) {
    // {sum, mx}
    lli flag = 1, mx = -1, sum = 0;

    for (auto val : adj[a]) {
        flag = 0;
        auto p = dfs(val);
        mx = max(mx, p.second);
        sum += p.first;
        leaves[a] += leaves[val];
    }

    if (flag) {
        // leaf
        leaves[a]++;
        return {valu[a], valu[a]};
    } else {
        lli cnt = leaves[a], val = valu[a];
        sum += val;
        mx = max(mx, sum / cnt + (sum % cnt != 0));
        return {sum, mx};
    }
}

void solve() {
    lli n, a;
    cin >> n;
    adj.resize(n + 2);

    for (lli i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
    }

    valu.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        valu.pb(a);
    }

    leaves.resize(n + 2, 0);
    auto ans = dfs(1);
    cout << ans.second << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}