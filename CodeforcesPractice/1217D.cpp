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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

bool cycle = false;
vector<lli> vis;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            vis[val] = 2;
        } else if (vis[val] == 1) {
            cycle = true;
            return;
        }
    }
}

void solve() {
    lli n, m, a, b;
    cin >> n >> m;

    adj.resize(n + 2);
    vector<pair<lli, lli>> store;
    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        store.pb({a, b});
        adj[a].pb(b);
    }

    vis.resize(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 2;
        }
        if (cycle) {
            break;
        }
    }

    if (cycle == false) {
        cout << "1" << endl;
        for (lli i = 0; i < m; i++) {
            cout << "1 ";
        }
        cout << endl;
    } else {
        cout << "2" << endl;
        for (auto edg : store) {
            if (edg.first > edg.second) {
                cout << "1 ";
            } else {
                cout << "2 ";
            }
        }
        cout << endl;
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