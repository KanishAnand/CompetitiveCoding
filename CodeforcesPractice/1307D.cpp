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

const lli INF = 1e14;

void dijkstra(vector<vector<lli>> &adj, vector<lli> &dis, lli src) {
    set<pair<lli, lli>> st;

    dis[src] = 0;
    st.insert({dis[src], src});

    while (!st.empty()) {
        auto it = st.begin();

        lli d = it->first, a = it->second;
        st.erase(it);

        for (auto child : adj[a]) {
            lli des = child, cost = 1;

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

void solve() {
    lli n, m, k, a, b;
    cin >> n >> m >> k;

    vector<lli> special(n + 2, 0);
    for (lli i = 0; i < k; i++) {
        cin >> a;
        special[a] = 1;
    }

    vector<vector<lli>> adj(n + 2);
    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<lli> dis_source(n + 2, INF), dis_dest(n + 2, INF);

    dijkstra(adj, dis_source, 1);
    dijkstra(adj, dis_dest, n);

    lli ans = dis_source[n];

    multiset<lli> st;
    vector<pair<lli, lli>> v;

    for (lli i = 1; i <= n; i++) {
        if (special[i]) {
            v.pb({dis_source[i] - dis_dest[i], i});
            st.insert(dis_dest[i]);
        }
    }

    sort(all(v));

    lli mx = -1, cnt = 0;
    for (lli i = 0; i < sz(v) - 1; i++) {
        auto pr = v[i];
        cnt++;
        st.erase(st.find(dis_dest[pr.second]));
        auto it = st.end();
        it--;
        lli val = *it;
        mx = max(mx, dis_source[pr.second] + val + 1);
    }

    ans = min(ans, mx);
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