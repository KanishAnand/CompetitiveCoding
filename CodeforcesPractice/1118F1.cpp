#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli ans = 0, blue = 0, red = 0;
lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            red++;
        } else if (val == 2) {
            blue++;
        }
        ve.pb(val);
    }
    return 0;
}

struct col {
    lli r, b;
};

vector<lli> vis;
vector<vector<lli>> adj;
vector<lli> v;
vector<struct col> colr;

struct col dfs(lli a) {
    if (v[a] == 1) {
        colr[a].r++;
    } else if (v[a] == 2) {
        colr[a].b++;
    }
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            struct col p;
            p = dfs(val);
            colr[a].r += p.r;
            colr[a].b += p.b;
            if ((colr[val].r == red && colr[val].b == 0) ||
                (colr[val].r == 0 && colr[val].b == blue)) {
                ans++;
            }
        }
    }
    return colr[a];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b;
    cin >> n;
    vis.resize(n + 2, 0);
    colr.resize(n + 2, {0, 0});
    adj.resize(n + 2);
    v.pb(0);
    input(n, v);
    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis[1] = 1;
    dfs(1);
    cout << ans << endl;
    rt;
}
