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

vector<lli> king, rankk, vis;
vector<vector<pair<lli, lli>>> adj;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    if (rankk[a] > rankk[b]) {
        rankk[a] += rankk[b];
        king[b] = king[a];
    } else {
        rankk[b] += rankk[a];
        king[a] = king[b];
    }
}

void dfs(lli a, lli sum, vector<lli> &result) {
    for (auto val : adj[a]) {
        if (vis[val.first] == 0) {
            vis[val.first] = 1;
            dfs(val.first, sum + val.second, result);
        }
    }

    result[a] = sum;
}

void solve() {
    lli n, a, b;
    cin >> n;

    king.resize(n + 2, 0);
    rankk.resize(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }
    vector<pair<lli, pair<lli, lli>>> edges;

    vector<vector<lli>> dist(n + 2, vector<lli>(n + 2, 0));
    lli cnt = 0;
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            cin >> a;
            if (a == 0) {
                cnt++;
            }
            dist[i + 1][j + 1] = a;
            if (i > j) {
                edges.pb({a, {i + 1, j + 1}});
            }
        }
    }

    for (lli i = 1; i <= n; i++) {
        if (dist[i][i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    if (cnt != n) {
        cout << "NO" << endl;
        return;
    }

    sort(all(edges));

    adj.resize(n + 2);
    for (auto ed : edges) {
        a = find(ed.second.first);
        b = find(ed.second.second);
        if (a != b) {
            adj[ed.second.second].pb({ed.second.first, ed.first});
            adj[ed.second.first].pb({ed.second.second, ed.first});
            merge(a, b);
        }
    }

    for (lli i = 1; i <= n; i++) {
        vis.clear();
        vis.resize(n + 2, 0);
        vis[i] = 1;
        vector<lli> result(n + 2, 0);
        dfs(i, 0, result);
        for (lli j = 1; j <= n; j++) {
            if (dist[i][j] != result[j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}