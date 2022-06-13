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
vector<lli> seg, v, lazy;

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

void push(lli pos) {
    lazy[2 * pos] += lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    seg[2 * pos] += lazy[pos];
    seg[2 * pos + 1] += lazy[pos];
    lazy[pos] = 0;
    return;
}

void update(lli pos, lli beg, lli end, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        seg[pos] += val;
        lazy[pos] += val;
        return;
    }

    update(2 * pos, beg, end, val, l, mid);
    update(2 * pos + 1, beg, end, val, mid + 1, r);
    seg[pos] = min(seg[2 * pos], seg[2 * pos + 1]);
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 1e17;
    }

    if (l != r) {
        push(pos);
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    return min(query(2 * pos, beg, end, l, mid),
               query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    lli n, a, m, l, r, val;
    cin >> n;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    seg.resize(4 * n + 2, 0);
    lazy.resize(4 * n + 2, 0);

    build(1, 0, n - 1);

    cin >> m;
    char ch;

    while (m--) {
        scanf("%lld%lld%c", &l, &r, &ch);

        if (ch == '\n') {
            lli ans;
            if (r >= l) {
                ans = query(1, l, r, 0, n - 1);
            } else {
                ans = query(1, l, n - 1, 0, n - 1);
                ans = min(ans, query(1, 0, r, 0, n - 1));
            }
            cout << ans << endl;
        } else {
            cin >> val;
            if (r >= l) {
                update(1, l, r, val, 0, n - 1);
            } else {
                update(1, l, n - 1, val, 0, n - 1);
                update(1, 0, r, val, 0, n - 1);
            }
        }
    }
}

int main(void) {
    solve();
    rt;
}