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

lli tmm = 1, root, cnt = 0;
vector<lli> vis, start_time, end_time, group, dist;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (a == root) {
            cnt++;
        }
        if (vis[val] == 0) {
            vis[val] = 1;
            start_time[val] = tmm;
            tmm++;
            dist[val] = dist[a] + 1;
            dfs(val);
            group[val] = cnt;
            end_time[val] = tmm;
            tmm++;
        }
    }
}

vector<lli> seg, v;

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
        cout << "DF" << endl;
        cout << seg[pos] << endl;
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    return query(2 * pos, beg, end, l, mid) +
           query(2 * pos + 1, beg, end, mid + 1, r);
}

void solve() {
    lli n, a, b, q;
    cin >> n;
    adj.resize(n + 2);
    vector<pair<lli, lli>> edg;
    edg.pb({0, 0});

    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        edg.pb({a, b});
    }

    vis.resize(n + 2, 0);
    start_time.resize(n + 2, 0);
    end_time.resize(n + 2, 0);
    group.resize(n + 2, 0);
    dist.resize(n + 2, 0);

    lli mx = -1;
    for (lli i = 1; i <= n; i++) {
        if (sz(adj[i]) > mx) {
            mx = sz(adj[i]);
            root = i;
        }
    }

    start_time[root] = tmm;
    tmm++;
    vis[root] = 1;
    dfs(root);
    end_time[root] = tmm;

    seg.resize(4 * tmm + 2, 0);
    v.resize(tmm + 2, 0);

    for (lli i = 1; i <= n; i++) {
        v[start_time[i]] = 1;
        v[end_time[i]] = -1;
    }

    build(1, 1, tmm);

    cin >> q;
    lli type;

    while (q--) {
        cin >> type >> a;
        if (type == 1) {
            lli ind1 = edg[a].first;
            lli ind2 = edg[a].second;
            if (start_time[ind1] > start_time[ind2]) {
                swap(ind1, ind2);
            }
            update(1, start_time[ind2], 1, 1, tmm);
            update(1, end_time[ind2], -1, 1, tmm);
        } else if (type == 2) {
            lli ind1 = edg[a].first;
            lli ind2 = edg[a].second;
            if (start_time[ind1] > start_time[ind2]) {
                swap(ind1, ind2);
            }
            update(1, start_time[ind2], 0, 1, tmm);
            update(1, end_time[ind2], 0, 1, tmm);
        } else {
            cin >> b;
            lli ind1 = a;
            lli ind2 = b;
            if (start_time[ind1] > start_time[ind2]) {
                swap(ind1, ind2);
            }
            cout << root << endl;
            cout << group[a] << " " << group[b] << endl;
            if (group[ind1] == group[ind2]) {
                lli val = query(1, start_time[ind1], start_time[ind2], 1, tmm);
                val--;
                lli x = dist[ind2] - dist[ind1];
                cout << x << endl;
                cout << val << endl;
                x = abs(x);
                if (x != val) {
                    cout << "-1" << endl;
                } else {
                    cout << x << endl;
                }
            } else {
                lli val1 = query(1, 1, start_time[ind1], 1, tmm);
                lli val2 = query(1, 1, start_time[ind2], 1, tmm);
                val1--;
                val2--;
                lli x1 = dist[ind1];
                lli x2 = dist[ind2];
                if (x1 != val1 || x2 != val2) {
                    cout << "-1" << endl;
                } else {
                    cout << x1 + x2 << endl;
                }
            }
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
