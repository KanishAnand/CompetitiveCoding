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
    lli n, a, m, b;
    cin >> n;
    vector<lli> bfs;
    vector<set<pair<lli, lli>>> adj(n + 2);
    vector<pair<lli, lli>> store;

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        store.pb({a, b});
    }

    vector<lli> ind(n + 3);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        ind[a] = i;
        bfs.pb(a);
    }

    for (lli i = 0; i < store.size(); i++) {
        a = store[i].first;
        b = store[i].second;
        adj[a].insert({ind[b], b});
        adj[b].insert({ind[a], a});
    }

    queue<lli> qu;
    vector<lli> vis(n + 2, 0);
    vis[1] = 1;
    qu.push(1);
    vector<lli> v;

    while (!qu.empty()) {
        a = qu.front();
        v.pb(a);
        qu.pop();
        for (auto it = adj[a].begin(); it != adj[a].end(); it++) {
            lli val = it->second;
            if (vis[val] == 0) {
                vis[val] = 1;
                qu.push(val);
            }
        }
    }

    lli flag = 0;
    for (lli i = 0; i < n; i++) {
        if (bfs[i] != v[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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