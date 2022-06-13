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

stack<lli> st;
vector<lli> vis, cycle;
vector<vector<lli>> adj;

void dfs_cycle(lli a, lli par) {
    for (auto val : adj[a]) {
        if (sz(cycle)) {
            return;
        }
        if (vis[val] == 0) {
            vis[val] = 1;
            st.push(val);
            dfs_cycle(val, a);
            if (!sz(cycle)) {
                st.pop();
            }
        } else if (vis[val] == 1 && val != par) {
            while (1) {
                lli node = st.top();
                st.pop();
                cycle.pb(node);
                if (node == val) {
                    break;
                }
            }
        }
    }
}

void dfs(lli a, lli &cnt) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            cnt++;
            dfs(val, cnt);
        }
    }
}

void solve() {
    while (!st.empty()) {
        st.pop();
    }
    vis.clear();
    adj.clear();
    cycle.clear();
    lli n, a, b;
    cin >> n;
    adj.resize(n + 2);
    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    st.push(1);
    dfs_cycle(1, 0);

    lli ans = 0;
    vis.clear();
    vis.resize(n + 2, 0);

    for (auto node : cycle) {
        vis[node] = 1;
    }

    for (auto node : cycle) {
        lli cnt = 1;
        dfs(node, cnt);
        // cout << node << " " << cnt << endl;
        ans += (cnt * (cnt - 1)) / 2 + (cnt * (n - cnt));
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