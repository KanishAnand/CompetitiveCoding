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

lli tot = 0;
vector<lli> vis, dp;
multiset<pair<lli, pair<lli, lli>>> st;
vector<vector<pair<lli, lli>>> adj;

void dfs(lli a) {
    lli flag = 0;
    for (auto v : adj[a]) {
        lli val = v.first, w = v.second;
        if (vis[val] == 0) {
            flag = 1;
            vis[val] = 1;
            dfs(val);
            dp[a] += dp[val];
            lli cnt = dp[val];
            tot += cnt * w;
            lli p = (w - w / 2) * cnt;
            st.insert({p, {w, cnt}});
        }
    }

    if (flag == 0) {
        dp[a] = 1;
    }
}

void solve() {
    lli n, a, s, b, w;
    cin >> n >> s;
    adj.clear();
    vis.clear();
    dp.clear();
    st.clear();
    tot = 0;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    dp.resize(n + 2, 0);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    vis[1] = 1;
    dfs(1);
    lli ans = 0;
    while (tot > s) {
        ans++;
        auto it = st.end();
        it--;
        tot -= it->first;
        lli w = (it->second).first;
        lli cnt = (it->second).second;
        w /= 2;
        lli p = (w - w / 2) * cnt;
        st.erase(it);
        st.insert({p, {w, cnt}});
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