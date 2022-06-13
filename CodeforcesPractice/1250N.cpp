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

vector<lli> vis;
vector<vector<pair<lli, lli>>> adj;

void dfs(lli a, lli par, lli &cyc, vector<lli> &ed) {
    for (auto val : adj[a]) {
        if (vis[val.first] == 0) {
            vis[val.first] = 1;
            if (cyc == 0) {
                ed.pb(val.second);
            }
            dfs(val.first, a, cyc, ed);
        } else if (val.first != par && cyc == 0 && vis[val.first] == 1) {
            cyc = 1;
            ed.pb(val.second);
        }
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    set<lli> v;
    vector<pair<lli, pair<lli, lli>>> edges;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        v.insert(a);
        v.insert(b);
        edges.pb({i + 1, {a, b}});
    }

    lli beg = 0;
    map<lli, lli> mp;
    for (auto val : v) {
        beg++;
        mp[val] = beg;
    }

    adj.clear();
    adj.resize(beg + 2);
    for (auto val : edges) {
        adj[mp[val.second.first]].pb({mp[val.second.second], val.first});
        adj[mp[val.second.second]].pb({mp[val.second.first], val.first});
    }

    vis.clear();
    vis.resize(beg + 2, 0);

    lli ans = 0;
    vector<pair<lli, lli>> ans_ed;

    for (lli i = 1; i <= beg; i++) {
        if (vis[i] == 0) {
            ans++;
            vector<lli> ed;
            vis[i] = 1;
            lli cyc = 0;
            dfs(i, 0, cyc, ed);
            if (cyc == 1) {
                lli ind = ed[sz(ed) - 1];
                ans_ed.pb({ind, edges[ind - 1].second.second});
            } else {
                for (auto val : ed) {
                    lli val1 = mp[edges[val - 1].second.first];
                    lli val2 = mp[edges[val - 1].second.second];
                    if (sz(adj[val1]) == 1) {
                        ans_ed.pb({val, edges[val - 1].second.first});
                        break;
                    }
                    if (sz(adj[val2]) == 1) {
                        ans_ed.pb({val, edges[val - 1].second.second});
                        break;
                    }
                }
            }
        }
    }

    cout << ans - 1 << endln;
    lli val = ans_ed[0].second;
    for (lli i = 1; i < ans_ed.size(); i++) {
        cout << ans_ed[i].first << " " << ans_ed[i].second << " " << val
             << endln;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}