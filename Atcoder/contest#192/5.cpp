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

struct edg {
    lli des, t, k;
};

void solve() {
    lli n, m, a, b, t, k, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<struct edg>> adj(n + 2);
    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> t >> k;
        struct edg edg1, edg2;
        edg1.des = b, edg1.t = t, edg1.k = k;
        edg2.des = a, edg2.t = t, edg2.k = k;
        adj[a].pb(edg1);
        adj[b].pb(edg2);
    }

    lli inf = -1;
    vector<lli> dis(n + 2, inf);
    set<pair<lli, lli>> st;

    dis[x] = 0;
    st.insert({dis[x], x});

    while (!st.empty()) {
        auto it = st.begin();
        lli d = it->first;
        lli a = it->second;
        // cout << d << " " << a << endl;
        st.erase(it);

        for (lli i = 0; i < adj[a].size(); i++) {
            lli des = adj[a][i].des;
            lli cost = adj[a][i].t;
            lli wait_time = 0;
            if (d % adj[a][i].k != 0) {
                lli p = d / adj[a][i].k;
                p++;
                // if (des == 3) {
                //     cout << p << endl;
                // }
                wait_time = p * adj[a][i].k - d;
            }
            lli final_cost = d + cost + wait_time;
            if (dis[des] == inf) {
                dis[des] = final_cost;
                st.insert({dis[des], des});
            } else if (dis[des] > final_cost) {
                dis[des] = final_cost;
                st.insert({dis[des], des});
            }
        }
    }

    lli ans = dis[y];
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