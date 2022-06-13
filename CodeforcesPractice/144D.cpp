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

    lli l, inf = 1e14;
    cin >> l;

    vector<lli> dis(n + 2, inf);
    set<pair<lli, lli>> st;
    dis[s] = 0;
    st.insert({dis[s], s});

    while (!st.empty()) {
        auto it = st.begin();
        lli d = it->first;
        lli a = it->second;
        st.erase(it);
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
    }

    lli ans = 0;
    for (lli i = 1; i <= n; i++) {
        if (dis[i] == l) {
            ans++;
        }
    }

    lli p = 0;
    for (lli i = 1; i <= n; i++) {
        for (lli j = 0; j < adj[i].size(); j++) {
            lli val = adj[i][j].first;
            lli w = adj[i][j].second;
            lli q1;

            if (dis[i] < l) {
                q1 = l - dis[i];
                if (q1 < w && (dis[val] + w - q1) > l) {
                    ans++;
                } else if (q1 < w && (dis[val] + w - q1) == l) {
                    p++;
                }
            }
        }
    }

    p /= 2;
    ans += p;
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