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
#define sz(x) (int)(x.size())
const int MOD = 1e9 + 7;
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
vector<int> v;
vector<bool> vis;
vector<vector<int>> adj;
vector<map<int, int>> mp;
int ans = 0;

void dfs(int a) {
    set<int> tmp;
    lli no = v[a];
    for (int i = 2; i <= sqrt(no); i++) {
        while (no % i == 0) {
            no /= i;
            tmp.insert(i);
            mp[a][i] = 1;
        }
        if (no == 1) {
            break;
        }
    }

    if (no != 1) {
        mp[a][no] = 1;
        tmp.insert(no);
    }

    if (tmp.size() != 0) {
        ans = max(ans, 1);
    }

    for (auto val : adj[a]) {
        if (!vis[val]) {
            vis[val] = 1;
            dfs(val);
            for (auto vv : tmp) {
                ans = max(ans, mp[a][vv] + mp[val][vv]);
                mp[a][vv] = max(mp[a][vv], mp[val][vv] + 1);
            }
        }
    }
}

void solve() {
    int n, a, b;
    cin >> n;
    adj.resize(n + 2);
    mp.resize(n + 2);
    v.pb(0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t; while(t--)
    solve();
    rt;
}