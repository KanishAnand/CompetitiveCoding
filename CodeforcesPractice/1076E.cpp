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

lli n;
vector<bool> vis;
vector<lli> seg, v, ans;
vector<vector<lli>> adj;
vector<vector<pair<lli, lli>>> store;

void update(lli pos, lli in, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r || l > in || r < in) {
        return;
    }
    if (l == r) {
        v[in] = val;
        seg[pos] = val;
        return;
    }
    if (in <= mid) {
        update(2 * pos, in, val, l, mid);
    } else {
        update(2 * pos + 1, in, val, mid + 1, r);
    }
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    return query(2 * pos, beg, end, l, mid) +
           query(2 * pos + 1, beg, end, mid + 1, r);
}

void dfs(lli a, lli level = 1) {
    for (auto val : store[a]) {
        lli ind = min(n, level + val.first);
        update(1, ind, v[ind] + val.second, 1, n);
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val, level + 1);
        }
    }

    lli an = query(1, level, n, 1, n);
    ans[a] = an;

    for (auto val : store[a]) {
        lli ind = min(n, level + val.first);
        update(1, ind, v[ind] - val.second, 1, n);
    }
}

void solve() {
    lli a, b;
    cin >> n;
    adj.resize(n + 2);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    lli m, ve, d, x;
    cin >> m;
    store.resize(n + 2);
    while (m--) {
        cin >> ve >> d >> x;
        store[ve].pb({d, x});
    }

    seg.resize(4 * n + 2, 0);
    v.resize(n + 2, 0);
    ans.resize(n + 2, 0);
    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    for (lli i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}