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
    lli n, a, m, b, c, k;
    cin >> n >> m;

    vector<vector<pair<lli, lli>>> adj(n + 2);
    vector<set<lli>> v(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    for (lli i = 1; i <= n; i++) {
        cin >> k;
        for (lli j = 0; j < k; j++) {
            cin >> a;
            v[i].insert(a);
        }
    }

    vector<lli> dis(n + 2, -1);

    lli beg = 0;
    while (v[1].find(beg) != v[1].end()) {
        beg++;
    }

    dis[1] = beg;
    set<pair<lli, lli>> st;
    st.insert({dis[1], 1});

    while (!st.empty()) {
        auto it = st.begin();
        a = it->second;

        for (lli i = 0; i < sz(adj[a]); i++) {
            b = adj[a][i].first;
            c = adj[a][i].second;
            lli val = dis[a] + c;
            lli ind = -1;
            if (b != n) {
                while (v[b].find(val) != v[b].end()) {
                    val++;
                }
            }

            if (dis[b] == -1) {
                dis[b] = val;
                st.insert({dis[b], b});
            } else if (dis[b] > val) {
                auto it2 = st.find({dis[b], b});
                if (it2 != st.end()) {
                    st.erase(it2);
                }
                dis[b] = val;
                st.insert({dis[b], b});
            }
        }

        st.erase(it);
    }

    cout << dis[n] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}