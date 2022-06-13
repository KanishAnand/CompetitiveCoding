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

struct edges {
    lli b, w, ind;
};

void solve() {
    lli n, a, m, b, w;
    cin >> n >> m;

    vector<vector<struct edges>> adj(n + 2);

    for (lli i = 0; i < m; i++) {
        struct edges tmp, tmp2;
        cin >> a >> tmp.b >> tmp.w;
        tmp.ind = i + 1;
        tmp2.ind = i + 1;
        tmp2.w = tmp.w;
        tmp2.b = a;
        adj[a].pb(tmp);
        adj[tmp.b].pb(tmp2);
    }

    lli root, inf = 1e17;
    cin >> root;

    vector<lli> dis(n + 2, inf), index(n + 2, inf), weights(n + 2, inf);
    vector<bool> vis(n + 2, 0);
    dis[root] = 0;
    index[root] = 0;
    weights[root] = 0;

    lli len = 0;
    vector<lli> ans;
    set<pair<lli, pair<lli, lli>>> st;
    // dist : node_no : index of edge
    st.insert({0, {root, 0}});

    while (!st.empty()) {
        auto it = st.begin();
        lli dist = (*it).first;
        lli node = (*it).second.first;
        lli ind = (*it).second.second;
        st.erase(it);
        if (vis[node] == 1) {
            continue;
        }
        len += weights[node];
        ans.pb(ind);
        vis[node] = 1;

        for (auto val : adj[node]) {
            lli new_node = val.b;
            if (vis[new_node] == 0) {
                lli new_dis = dist + val.w;
                if (new_dis < dis[new_node]) {
                    auto itt =
                        st.find({dis[new_node], {new_node, index[new_node]}});
                    if (itt != st.end()) {
                        st.erase(itt);
                    }
                    st.insert({new_dis, {new_node, val.ind}});
                    dis[new_node] = new_dis;
                    weights[new_node] = val.w;
                    index[new_node] = val.ind;
                } else if (new_dis == dis[new_node]) {
                    if (val.w < weights[new_node]) {
                        auto itt = st.find(
                            {dis[new_node], {new_node, index[new_node]}});
                        if (itt != st.end()) {
                            st.erase(itt);
                        }
                        st.insert({new_dis, {new_node, val.ind}});
                        weights[new_node] = val.w;
                        index[new_node] = val.ind;
                    }
                }
            }
        }
    }

    cout << len << endln;
    sort(all(ans));
    for (lli i = 1; i < sz(ans); i++) {
        cout << ans[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}