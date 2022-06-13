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
lli n, flag = 0;
vector<vector<lli>> adj;

void dfs(lli a, lli b, vector<bool> &vis, stack<lli> &st) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            if (flag == 0) {
                st.push(val);
            }
            if (val == b) {
                flag = 1;
                return;
            }
            dfs(val, b, vis, st);
            if (flag == 0) {
                // alternate way ????????
                st.pop();
            }
        }
    }
}

void dfs2(lli a, vector<bool> &vis2, vector<vector<lli>> &store,
          vector<lli> &len, lli &ans) {
    for (auto val : adj[a]) {
        if (vis2[val] == 0) {
            vis2[val] = 1;
            dfs2(val, vis2, store, len, ans);
            store[a].pb(len[val] + 1);
            len[a] = max(len[a], len[val] + 1);
        }
    }

    sort(store[a].rbegin(), store[a].rend());
    ans = max(ans, len[a]);
    if (store[a].size() >= 1) {
        ans = max(ans, store[a][0]);
    }
    if (store[a].size() >= 2) {
        lli val = store[a][0] + store[a][1];
        ans = max(ans, val);
    }
}

void solve() {
    lli a, b;
    cin >> n;
    adj.resize(n + 2);
    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    lli ans = 0;

    for (lli i = 1; i <= n; i++) {
        for (lli j = i + 1; j <= n; j++) {
            vector<bool> vis(n + 2, 0);
            stack<lli> st;
            st.push(i);
            vis[i] = 1;
            flag = 0;
            dfs(i, j, vis, st);
            lli len1 = st.size() - 1;
            vector<bool> vis2(n + 2, 0);
            while (!st.empty()) {
                a = st.top();
                st.pop();
                vis2[a] = 1;
            }

            vector<lli> len(n + 2, 0);
            vector<vector<lli>> store(n + 2);
            lli mx = 0;

            for (lli k = 1; k <= n; k++) {
                if (vis2[k] == 1) {
                    continue;
                }
                lli p = 0;
                vis2[k] = 1;
                dfs2(k, vis2, store, len, p);
                mx = max(mx, p);
            }

            ans = max(ans, len1 * mx);
        }
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