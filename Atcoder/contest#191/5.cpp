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

void solve() {
    lli n, m, a, b, c;
    cin >> n >> m;

    vector<vector<pair<lli, lli>>> adj(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    lli inf = 1e14;

    for (lli i = 1; i <= n; i++) {
        vector<lli> vis(n + 2, 0);
        vector<lli> dis(n + 2, inf);
        set<pair<lli, lli>> st;
        st.insert({dis[i], i});

        lli ans = -1, flag = 0;

        while (!st.empty()) {
            auto it = st.begin();
            lli d = it->first;
            lli a = it->second;
            st.erase(it);

            if (a == i && flag == 1) {
                if (ans == -1) {
                    ans = d;
                }
                ans = min(ans, d);
            }

            if (flag == 0) {
                d = 0;
            }
            if (vis[a] == 1) {
                continue;
            }

            for (lli i = 0; i < adj[a].size(); i++) {
                lli des = adj[a][i].first;
                lli cost = adj[a][i].second;
                if (dis[des] == inf) {
                    dis[des] = d + cost;
                    st.insert({dis[des], des});
                } else if (dis[des] > d + cost) {
                    dis[des] = d + cost;
                    st.insert({dis[des], des});
                }
            }

            vis[a] = 1;
            flag = 1;
        }

        cout << ans << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}