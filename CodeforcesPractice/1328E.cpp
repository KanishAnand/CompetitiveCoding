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

vector<vector<lli>> adj;
vector<lli> vis, level;
vector<lli> start, finish, parent;
lli tt = 1;

lli dfs(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            level[val] = level[a] + 1;
            parent[val] = a;
            start[val] = tt;
            tt++;
            dfs(val);
            finish[val] = tt;
            tt++;
        }
    }
}

void solve() {
    lli n, a, b, m, k;
    cin >> n >> m;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    start.resize(n + 2, 0);
    finish.resize(n + 2, 0);
    level.resize(n + 2, 0);
    parent.resize(n + 2, 0);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    start[1] = tt;
    tt++;
    level[1] = 1;
    vis[1] = 1;
    parent[1] = 1;
    dfs(1);
    finish[1] = tt;

    for (lli p = 0; p < m; p++) {
        cin >> k;
        if (k == 1) {
            cin >> a;
            cout << "YES" << endl;
            continue;
        }

        vector<pair<lli, lli>> v;
        for (lli j = 0; j < k; j++) {
            cin >> a;
            lli val = parent[a];
            v.pb({level[val], val});
        }

        sort(v.rbegin(), v.rend());
        lli flag = 1;

        for (lli i = 1; i < v.size(); i++) {
            if (v[i].first == v[i - 1].first) {
                if (v[i].second != v[i - 1].second) {
                    flag = 0;
                    cout << "NO" << endl;
                    break;
                }
            } else if (start[v[i].second] > start[v[i - 1].second] ||
                       finish[v[i].second] < finish[v[i - 1].second]) {
                flag = 0;
                cout << "NO" << endl;
                break;
            }
        }

        if (flag == 1) {
            cout << "YES" << endl;
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