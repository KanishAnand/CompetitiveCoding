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

lli flag = 1;
vector<lli> color;
vector<vector<pair<lli, lli>>> adj;

void dfs(lli a) {
    for (auto pr : adj[a]) {
        if (pr.second == 1) {
            // locked
            if (color[pr.first] == -1) {
                color[pr.first] = 1 - color[a];
                dfs(pr.first);
            } else if (color[pr.first] == color[a]) {
                flag = 0;
                return;
            }
        } else {
            // unlocked
            if (color[pr.first] == -1) {
                color[pr.first] = color[a];
                dfs(pr.first);
            } else if (color[pr.first] != color[a]) {
                flag = 0;
                return;
            }
        }
    }
}

void solve() {
    lli n, a, m;
    cin >> n >> m;

    vector<lli> v;
    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(1 - a);
    }

    vector<vector<lli>> room(n + 2);
    lli cnt;
    for (lli i = 1; i <= m; i++) {
        cin >> cnt;
        for (lli j = 0; j < cnt; j++) {
            cin >> a;
            room[a].pb(i);
        }
    }

    adj.resize(m + 2);
    for (lli i = 1; i <= n; i++) {
        adj[room[i][0]].pb({room[i][1], v[i]});
        adj[room[i][1]].pb({room[i][0], v[i]});
    }

    color.resize(m + 2, -1);

    for (lli i = 1; i <= m; i++) {
        if (color[i] != -1) {
            continue;
        }
        color[i] = 0;
        dfs(i);
        if (flag == 0) {
            break;
        }
    }

    if (flag == 0) {
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