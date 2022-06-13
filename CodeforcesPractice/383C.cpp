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

lli tim = 1, INF = -1e9;
vector<pair<lli, lli>> seg, lazy;
vector<lli> vis, start, finish, level;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            start[val] = tim++;
            level[val] = level[a] + 1;
            dfs(val);
            finish[val] = tim++;
        }
    }
}

void push(lli pos) {
    lazy[2 * pos].first += lazy[pos].first;
    lazy[2 * pos].second += lazy[pos].second;
    lazy[2 * pos + 1].first += lazy[pos].first;
    lazy[2 * pos + 1].second += lazy[pos].second;
    seg[2 * pos].first += lazy[pos].first;
    seg[2 * pos].second += lazy[pos].second;
    seg[2 * pos + 1].first += lazy[pos].first;
    seg[2 * pos + 1].second += lazy[pos].second;
    lazy[pos] = {0, 0};
    return;
}

void update(lli pos, lli beg, lli end, lli val, lli l, lli r, lli depth) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        if (depth) {
            seg[pos].first += val;
            lazy[pos].first += val;
        } else {
            seg[pos].second += val;
            lazy[pos].second += val;
        }
        return;
    }

    update(2 * pos, beg, end, val, l, mid, depth);
    update(2 * pos + 1, beg, end, val, mid + 1, r, depth);
    return;
}

pair<lli, lli> query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return {INF, INF};
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    pair<lli, lli> a = query(2 * pos, beg, end, l, mid);
    pair<lli, lli> b = query(2 * pos + 1, beg, end, mid + 1, r);
    // cout << a << " " << b << endl;
    return max(a, b);
}

void solve() {
    lli n, m, a, b;
    cin >> n >> m;
    vector<lli> v;
    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    adj.resize(n + 2);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    // calculate start and finish time
    level.resize(n + 2, 0);
    vis.resize(n + 2, 0);
    start.resize(n + 2, 0);
    finish.resize(n + 2, 0);
    vis[1] = 1;
    level[1] = 1;
    start[1] = tim++;
    dfs(1);
    finish[1] = tim;

    seg.resize(4 * tim + 2, {0, 0});
    lazy.resize(4 * tim + 2, {0, 0});

    while (m--) {
        lli op, x, val;
        cin >> op >> x;
        if (op == 1) {
            cin >> val;
            update(1, start[x], finish[x], val, 0, tim, level[x] % 2);
        } else {
            pair<lli, lli> pr = query(1, start[x], start[x], 0, tim);
            lli ans = v[x];
            if (level[x] % 2 == 1) {
                ans += pr.first - pr.second;
            } else {
                ans += -pr.first + pr.second;
            }
            cout << ans << endl;
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