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

int ans = 0, n;
vector<int> cost, v, vis;

int dfs(int a, vector<int> &st) {
    st.pb(a);
    int val = v[a];
    if (vis[val] == 0) {
        vis[val] = 1;
        dfs(val, st);
        vis[val] = 2;
    } else {
        if (vis[val] == 1) {
            int mn = 1e5;
            for (int i = st.size() - 1; i >= 0; i--) {
                mn = min(mn, cost[st[i]]);
                if (st[i] == val) {
                    break;
                }
            }
            ans += mn;
        }
    }
    st.pop_back();
    return 0;
}

void solve() {
    int a;
    cin >> n;
    cost.pb(0);
    v.pb(0);

    for (int i = 0; i < n; i++) {
        cin >> a;
        cost.pb(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vis.resize(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vector<int> st;
            dfs(i, st);
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}