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
    lli n, a, k, b;
    cin >> n >> k;
    vector<vector<lli>> adj;
    adj.resize(n + 2);
    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<lli> level(n + 2, 0), vis(n + 2, 0), parent(n + 2, 0), deg(n + 2, 0);
    vector<lli> bel(n + 2, 0);

    level[1] = 1;
    vis[1] = 1;
    queue<lli> qu;
    qu.push(1);

    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (lli i = 0; i < adj[a].size(); i++) {
            lli val = adj[a][i];
            if (vis[val] == 0) {
                vis[val] = 1;
                parent[val] = a;
                level[val] = level[a] + 1;
                qu.push(val);
            }
        }
    }

    set<pair<lli, lli>> st;

    for (lli i = 2; i <= n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1) {
            st.insert({level[i] - 1, i});
        }
    }

    lli cnt = k, ans = 0;

    while (cnt > 0) {
        auto it = st.end();
        it--;
        pair<lli, lli> pr = *it;
        lli score = pr.first, node = pr.second;
        ans += score;
        // cout << score << " " << node << endl;
        cnt--;
        st.erase(it);
        lli pnode = parent[node];
        bel[pnode] += bel[node] + 1;
        deg[pnode]--;

        if (deg[pnode] == 1 && pnode != 1) {
            st.insert({level[pnode] - bel[pnode] - 1, pnode});
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