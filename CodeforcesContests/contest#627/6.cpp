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
// cout << fixed << setprecision(0) << pi <<endl;

vector<vector<lli>> adj;
vector<lli> vis, color, cnt, vis2, ans;

lli dfs(lli a) {
    lli sum = color[a] == 1 ? 1 : -1;

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            lli c = dfs(val);
            // if (c >= 0) {
            sum += max(0ll, c);
            // }
        }
    }

    cnt[a] = sum;
    return sum;
}

lli get_ans(lli a) {
    for (auto val : adj[a]) {
        if (vis2[val] == 0) {
            vis2[val] = 1;
            if (cnt[val] < 0) {
                ans[val] = max(cnt[val], ans[a] + cnt[val]);
                get_ans(val);
            } else {
                ans[val] = max(cnt[val], ans[a]);
                get_ans(val);
            }
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b;
    cin >> n;
    vis.resize(n + 2, 0);
    vis2.resize(n + 2, 0);
    ans.resize(n + 2, -1e10);
    cnt.resize(n + 2, 0);
    color.pb(-1);

    fr(i, 0, n) {
        cin >> a;
        color.pb(a);
    }

    adj.resize(n + 2);

    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis[1] = 1;
    dfs(1);
    vis2[1] = 1;
    ans[1] = cnt[1];
    get_ans(1);
    fr(i, 1, n + 1) {
        cout << ans[i] << " ";
    }
    cout << endl;

    rt;
}
