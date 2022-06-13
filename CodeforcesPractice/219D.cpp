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
vector<vector<lli>> adj, adj2;
vector<lli> vis, dis, cnt;
lli ansroot = 0;

lli dfs(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dis[val] = dis[a] + 1;
            cnt[val] = cnt[a];
            dfs(val);
        }
    }

    for (lli i = 0; i < adj2[a].size(); i++) {
        lli val = adj2[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dis[val] = dis[a] + 1;
            cnt[val] = cnt[a] + 1;
            ansroot++;
            dfs(val);
        }
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    adj.resize(n + 2);
    adj2.resize(n + 2);
    vis.resize(n + 2, 0);
    dis.resize(n + 2, 0);
    cnt.resize(n + 2, 0);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj2[b].pb(a);
    }

    vis[1] = 1;
    dfs(1);
    lli mn = n + 2;
    vector<lli> ans(n + 2);
    ans[1] = ansroot;

    for (lli i = 1; i <= n; i++) {
        lli val = ans[1] - cnt[i] + (dis[i] - cnt[i]);
        ans[i] = val;
        mn = min(mn, val);
    }

    cout << mn << endl;

    for (lli i = 1; i <= n; i++) {
        if (ans[i] == mn) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}