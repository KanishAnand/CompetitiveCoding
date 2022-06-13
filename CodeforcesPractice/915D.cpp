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
const double PI = 3.14159265358979323846264338;
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
vector<lli> vis, cycle;
stack<lli> st;
lli cyc = 0, check = 0;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            if (cyc == 0) {
                st.push(val);
            }
            dfs(val);
            if (cyc == 0) {
                st.pop();
            }
            vis[val] = 2;
        } else if (vis[val] == 1 && cyc == 0) {
            cyc = 1;
            while (1) {
                lli a = st.top();
                st.pop();
                cycle.pb(a);
                if (a == val) {
                    break;
                }
            }
            reverse(all(cycle));
            return;
        }
    }
}

void dfs2(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs2(val);
            vis[val] = 2;
        } else if (vis[val] == 1) {
            check = 1;
            return;
        }
    }
}

void solve() {
    lli n, a, m, b;
    cin >> n >> m;
    adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    vis.resize(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            st.push(i);
            dfs(i);
            vis[i] = 2;
            if (cyc == 1) {
                break;
            }
            while (!st.empty()) {
                st.pop();
            }
        }
    }

    if (cyc == 0) {
        cout << "YES" << endl;
        return;
    }

    for (lli i = 0; i < sz(cycle); i++) {
        vis.clear();
        vis.resize(n + 2, 0);
        a = cycle[i];
        b = cycle[(i + 1) % (sz(cycle))];
        lli ind;
        for (lli j = 0; j < adj[a].size(); j++) {
            if (adj[a][j] == b) {
                ind = j;
                break;
            }
        }
        adj[a].erase(adj[a].begin() + ind);

        check = 0;
        for (lli j = 1; j <= n; j++) {
            if (vis[j] == 0) {
                vis[j] = 1;
                dfs2(j);
                vis[j] = 2;
            }
        }

        adj[a].pb(b);
        if (check == 0) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}