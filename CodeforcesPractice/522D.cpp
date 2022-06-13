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

lli inf = 1e10;

struct qr {
    lli l, r, ind;
};

bool compare(struct qr a, struct qr b) {
    return a.l < b.l;
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
    seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
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
    seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return inf;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    return min(query(2 * pos, beg, end, l, mid),
               query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    lli n, a, m;
    cin >> n >> m;
    vector<lli> inp;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        inp.pb(a);
    }

    map<lli, lli> mp;
    vector<lli> next_same(n + 2, -1);

    for (lli i = n - 1; i >= 0; i--) {
        if (mp[inp[i]] != 0) {
            next_same[i] = mp[inp[i]];
        }
        mp[inp[i]] = i;
    }

    seg.resize(4 * n + 2, inf);
    v.resize(n + 2, inf);

    map<lli, lli> new_map;

    for (lli i = 0; i < n; i++) {
        if (new_map[inp[i]] != 0) {
            v[i] = i + 1 - new_map[inp[i]];
        }
        new_map[inp[i]] = i + 1;
    }

    build(1, 0, n - 1);

    vector<struct qr> quer;

    for (lli i = 0; i < m; i++) {
        struct qr tmp;
        cin >> tmp.l >> tmp.r;
        tmp.ind = i;
        quer.pb(tmp);
    }

    lli beg = 0;
    sort(all(quer), compare);
    vector<lli> ans(m + 2, -1);

    lli l, r, ind;
    for (lli i = 0; i < sz(quer); i++) {
        l = quer[i].l;
        r = quer[i].r;
        ind = quer[i].ind;
        l--;
        r--;
        for (lli j = beg; j < l; j++) {
            if (next_same[j] != -1) {
                update(1, next_same[j], inf, 0, n - 1);
            }
        }

        beg = l;
        lli an = query(1, l, r, 0, n - 1);
        if (an == inf) {
            an = -1;
        }
        ans[ind] = an;
    }

    for (lli i = 0; i < m; i++) {
        cout << ans[i] << endln;
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
