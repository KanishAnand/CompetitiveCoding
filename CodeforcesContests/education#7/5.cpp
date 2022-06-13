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
vector<lli> seg, v, segmax;

lli build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return -1;
    } else if (l == r) {
        seg[pos] = l;
        return seg[pos];
    } else {
        lli a = build(2 * pos, l, mid);
        lli b = build(2 * pos + 1, mid + 1, r);
        if (a == -1 && b == -1) {
            return seg[pos];
        }
        lli val1 = 1e9;
        lli val2 = 1e9;
        if (a != -1) {
            val1 = v[a];
        }
        if (b != -1) {
            val2 = v[b];
        }
        if (val1 < val2) {
            seg[pos] = a;
        } else {
            seg[pos] = b;
        }
    }
    return seg[pos];
}

lli buildmax(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return -1;
    } else if (l == r) {
        segmax[pos] = l;
        return segmax[pos];
    } else {
        lli a = buildmax(2 * pos, l, mid);
        lli b = buildmax(2 * pos + 1, mid + 1, r);
        if (a == -1 && b == -1) {
            return segmax[pos];
        }
        lli val1 = -1, val2 = -1;
        if (a != -1) {
            val1 = v[a];
        }
        if (b != -1) {
            val2 = v[b];
        }
        if (val1 > val2) {
            segmax[pos] = a;
        } else {
            segmax[pos] = b;
        }
    }
    return segmax[pos];
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r) {
        return -1;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    if (end < l || beg > r) {
        return -1;
    } else {
        lli mid = (l + r) / 2;
        lli a = query(2 * pos, beg, end, l, mid);
        lli b = query(2 * pos + 1, beg, end, mid + 1, r);
        if (a == -1 && b == -1) {
            return -1;
        }
        lli val1 = 1e9, val2 = 1e9;
        if (a != -1) {
            val1 = v[a];
        }
        if (b != -1) {
            val2 = v[b];
        }
        if (val1 < val2) {
            return a;
        } else {
            return b;
        }
    }
}

lli querymax(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r) {
        return -1;
    }
    if (beg <= l && end >= r) {
        return segmax[pos];
    }
    if (end < l || beg > r) {
        return -1;
    } else {
        lli mid = (l + r) / 2;
        lli a = querymax(2 * pos, beg, end, l, mid);
        lli b = querymax(2 * pos + 1, beg, end, mid + 1, r);
        if (a == -1 && b == -1) {
            return -1;
        }
        lli val1 = -1, val2 = -1;
        if (a != -1) {
            val1 = v[a];
        }
        if (b != -1) {
            val2 = v[b];
        }
        if (val1 > val2) {
            return a;
        } else {
            return b;
        }
    }
}

void solve() {
    lli n, a, m, l, r, x;
    cin >> n >> m;
    seg.resize(4 * n + 2, -1);
    segmax.resize(4 * n + 2, -1);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    build(1, 0, n - 1);
    buildmax(1, 0, n - 1);

    for (lli i = 0; i < m; i++) {
        cin >> l >> r >> x;
        l--;
        r--;
        lli val1 = query(1, l, r, 0, n - 1);
        lli val2 = querymax(1, l, r, 0, n - 1);
        if (v[val1] != x) {
            cout << val1 + 1 << endln;
        } else if (v[val2] != x) {
            cout << val2 + 1 << endln;
        } else {
            cout << "-1" << endln;
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