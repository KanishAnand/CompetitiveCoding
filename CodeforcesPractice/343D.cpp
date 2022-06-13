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

lli n, timer = 1;
vector<vector<lli>> adj;
vector<lli> vis, start, finish;
vector<pair<lli, lli>> seg, lazy;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            start[val] = timer;
            timer++;
            dfs(val);
            finish[val] = timer;
            timer++;
        }
    }
}

void push(lli pos) {
    if (lazy[2 * pos].first < lazy[pos].first) {
        lazy[2 * pos].first = lazy[pos].first;
        if (lazy[pos].second == 1) {
            lazy[2 * pos].second = 1;
        } else {
            lazy[2 * pos].second -= 1;
        }
    }
    if (lazy[2 * pos + 1].first < lazy[pos].first) {
        lazy[2 * pos + 1].first = lazy[pos].first;
        if (lazy[pos].second == 1) {
            lazy[2 * pos + 1].second = 1;
        } else {
            lazy[2 * pos + 1].second -= 1;
        }
    }

    if (seg[2 * pos].first < lazy[pos].first) {
        seg[2 * pos].first = lazy[pos].first;
        if (lazy[pos].second == 1) {
            seg[2 * pos].second = 1;
        } else {
            seg[2 * pos].second -= 1;
        }
    }
    if (seg[2 * pos + 1].first < lazy[pos].first) {
        seg[2 * pos + 1].first = lazy[pos].first;
        if (lazy[pos].second == 1) {
            seg[2 * pos + 1].second = 1;
        } else {
            seg[2 * pos + 1].second -= 1;
        }
    }
    lazy[pos] = {0, 0};
    return;
}

void update(lli pos, lli beg, lli end, lli val1, lli val2, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        seg[pos].first = val1;
        if (val2 == 1) {
            seg[pos].second = val2;
        } else {
            seg[pos].second += val2;
        }
        lazy[pos].first = val1;
        lazy[pos].second = val2;
        return;
    }

    update(2 * pos, beg, end, val1, val2, l, mid);
    update(2 * pos + 1, beg, end, val1, val2, mid + 1, r);
    return;
}

pair<lli, lli> query(lli pos, lli beg, lli l, lli r) {
    if (l > r || beg < l || beg > r) {
        return {0, 0};
    }

    if (l != r) {
        push(pos);
    }

    if (l == r && beg == l) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    pair<lli, lli> p1 = query(2 * pos, beg, l, mid);
    pair<lli, lli> p2 = query(2 * pos + 1, beg, mid + 1, r);
    if (p1.first != 0) {
        return p1;
    } else {
        return p2;
    }
}

void solve() {
    lli a, b;
    cin >> n;
    adj.resize(n + 2);
    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    start.resize(n + 2, 0);
    finish.resize(n + 2, 0);
    vis.resize(n + 2, 0);

    vis[1] = 1;
    start[1] = timer;
    timer++;
    dfs(1);
    finish[1] = timer;

    lli inf = -1e15;
    seg.resize(4 * timer + 2, {0, inf});
    lazy.resize(4 * timer + 2, {0, 0});

    lli q, v;
    cin >> q;
    lli cnt = 1;

    while (q--) {
        cin >> a >> v;
        if (a == 1) {
            update(1, start[v], finish[v], cnt, 1, 1, timer);
        } else if (a == 2) {
            update(1, start[1], start[v], cnt, -cnt, 1, timer);
        } else {
            pair<lli, lli> p1, p2;
            p1 = query(1, start[v], 1, timer);
            p2 = query(1, finish[v], 1, timer);
            if (p1.first == 0) {
                cout << "0" << endl;
            } else if (p1.first == p2.first && p1.second == 1) {
                cout << "1" << endl;
            } else if (p1.first == p2.first && p1.second > inf &&
                       p1.second == p2.second) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
        cnt++;
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