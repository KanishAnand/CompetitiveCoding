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

vector<lli> king;

lli find(lli a) {
    if (king[a] != a) {
        king[a] = find(king[a]);
        return king[a];
    } else {
        return a;
    }
}

void merge(lli a, lli b) {
    king[b] = king[a];
}

void solve() {
    lli n, m, d;
    cin >> n >> m >> d;
    king.resize(n + 2, 0);

    for (lli i = 1; i <= n; i++) {
        king[i] = i;
    }

    lli a, b, deg = 0;

    vector<vector<lli>> adj(n + 2);
    vector<pair<lli, lli>> edg;
    map<lli, lli> mp;

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        if (a == 1) {
            deg++;
            mp[b] = 1;
        } else {
            edg.pb({a, b});
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }

    if (d > deg) {
        cout << "NO" << endl;
        return;
    }

    for (auto val : edg) {
        lli p = find(val.first);
        lli q = find(val.second);
        if (p != q) {
            merge(p, q);
        }
    }

    vector<vector<lli>> comp(n + 2);
    set<lli> st;
    for (lli i = 2; i <= n; i++) {
        lli p = find(i);
        comp[p].pb(i);
        st.insert(p);
    }

    lli no = sz(st);
    if (d < no) {
        cout << "NO" << endl;
        return;
    }

    queue<lli> qu;
    vector<bool> vis(n + 2, 0);
    vis[1] = 1;
    vector<pair<lli, lli>> ans;

    for (auto val : st) {
        for (auto vv : comp[val]) {
            if (mp[vv] == 1) {
                qu.push(vv);
                vis[vv] = 1;
                ans.pb({1, vv});
                break;
            }
        }
    }

    for (lli i = 2; i <= n; i++) {
        if (qu.size() == d) {
            break;
        }
        if (mp[i] == 1 && vis[i] == 0) {
            vis[i] = 1;
            ans.pb({1, i});
            qu.push(i);
        }
    }

    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (auto val : adj[a]) {
            if (vis[val] == 0) {
                vis[val] = 1;
                qu.push(val);
                ans.pb({a, val});
            }
        }
    }

    cout << "YES" << endl;
    for (auto val : ans) {
        cout << val.first << " " << val.second << endln;
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