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
    lli n, a, m, s, b, c;
    cin >> n >> m >> s;
    vector<vector<pair<lli, lli>>> adj;
    adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    lli INF = 1e14;

    vector<lli> dis(n + 2, INF);
    set<pair<lli, lli>> st;
    dis[s] = 0;
    st.insert({dis[s], s});

    while (!st.empty()) {
        auto it = st.begin();

        lli d = it->first, a = it->second;
        st.erase(it);

        for (auto child : adj[a]) {
            lli des = child.first, cost = child.second;

            if (dis[des] == INF) {
                dis[des] = d + cost;
                st.insert({dis[des], des});
            } else if (dis[des] > d + cost) {
                st.erase({dis[des], des});
                dis[des] = d + cost;
                st.insert({dis[des], des});
            }
        }
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