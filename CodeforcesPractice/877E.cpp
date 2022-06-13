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

vector<vector<lli>> adj;
vector<bool> vis;
vector<lli> start, finish;
lli tmm = 1;
vector<lli> seg, v, lazy;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            start[val] = tmm;
            tmm++;
            dfs(val);
            finish[val] = tmm;
            tmm++;
        }
    }
}

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = v[l];
        return;
    }
    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

void push(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    lazy[2 * pos] = lazy[pos] - lazy[2 * pos];
    lazy[2 * pos + 1] = lazy[pos] - lazy[2 * pos + 1];
    seg[2 * pos] = mid - l + 1 - seg[2 * pos];
    seg[2 * pos + 1] = r - (mid + 1) + 1 - seg[2 * pos + 1];
    lazy[pos] = 0;
    return;
}

void update(lli pos, lli beg, lli end, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        if (lazy[pos] == 1) {
            push(pos, l, r);
        }
    }

    if (beg <= l && end >= r) {
        seg[pos] = (r - l + 1) - seg[pos];
        lazy[pos] = 1 - lazy[pos];
        return;
    }

    update(2 * pos, beg, end, l, mid);
    update(2 * pos + 1, beg, end, mid + 1, r);
    seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }

    if (l != r) {
        if (lazy[pos] == 1) {
            push(pos, l, r);
        }
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;
    return query(2 * pos, beg, end, l, mid) +
           query(2 * pos + 1, beg, end, mid + 1, r);
}

void solve() {
    lli n, a, q;
    cin >> n;
    adj.resize(n + 2);
    for (lli i = 2; i <= n; i++) {
        cin >> a;
        adj[a].pb(i);
        adj[i].pb(a);
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    start.resize(n + 2, 0);
    finish.resize(n + 2, 0);
    start[1] = tmm;
    tmm++;
    dfs(1);
    finish[1] = tmm;

    seg.resize(4 * tmm + 2, 0);
    lazy.resize(4 * tmm + 2, 0);
    v.resize(tmm + 2, 0);

    for (lli i = 1; i <= n; i++) {
        cin >> a;
        v[start[i]] = a;
        v[finish[i]] = a;
    }

    build(1, 1, tmm);

    cin >> q;
    string st;
    lli u;
    while (q--) {
        cin >> st;
        cin >> u;
        if (st == "get") {
            lli an = query(1, start[u], finish[u], 1, tmm);
            cout << an / 2 << endl;
        } else {
            update(1, start[u], finish[u], 1, tmm);
        }
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