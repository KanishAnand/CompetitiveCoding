#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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

void solve() {
    lli n, a, b;
    cin >> n;
    vector<lli> v, tmp;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        tmp.pb(a);
    }

    vector<vector<lli>> adj;
    adj.resize(n + 2);

    for (lli bit = 0; bit < 60; bit++) {
        vector<lli> st;
        for (lli i = 0; i < n; i++) {
            lli rem = tmp[i] % 2;
            tmp.pb(tmp[i] / 2);
            tmp[i] /= 2;

            if (rem == 1) {
                st.pb(i);
            }
        }
        if (st.size() >= 3) {
            cout << "3" << endl;
            return;
        } else if (st.size() == 2) {
            a = st[0];
            b = st[1];
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }

    lli ans = 1e10;
    vector<lli> vis(n + 2, -1), level(n + 2, 0), parent(n + 2, -1);

    for (lli src = 0; src < n; src++) {
        vis[src] = src;
        level[src] = 1;
        queue<lli> qu;
        qu.push(src);

        while (!qu.empty()) {
            a = qu.front();
            qu.pop();
            lli child;
            for (lli i = 0; i < adj[a].size(); i++) {
                child = adj[a][i];
                if (vis[child] != src) {
                    level[child] = level[a] + 1;
                    parent[child] = a;
                    vis[child] = src;
                    qu.push(child);
                } else if (child != parent[a] && parent[child] != a) {
                    lli val = level[a] + level[child] - 1;
                    if (child != 0 && val >= 3) {
                        ans = min(ans, val);
                    }
                }
            }
        }
    }

    if (ans == 1e10) {
        ans = -1;
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