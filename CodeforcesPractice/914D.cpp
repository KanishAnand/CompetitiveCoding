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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

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
    seg[pos] = __gcd(seg[2 * pos], seg[2 * pos + 1]);
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
    seg[pos] = __gcd(seg[2 * pos], seg[2 * pos + 1]);

    return;
}

void query(lli pos, lli beg, lli end, lli l, lli r, lli x, lli &cnt) {
    if (cnt >= 2) {
        return;
    }

    if (l > r || end < l || beg > r) {
        return;
    }

    if (beg <= l && end >= r) {
        if (seg[pos] % x == 0) {
            return;
        } else {
            if (r - l + 1 == 1) {
                cnt++;
                return;
            }

            lli mid = (l + r) / 2;
            if (seg[2 * pos] % x != 0 && seg[2 * pos + 1] % x != 0) {
                cnt += 2;
            } else if (seg[2 * pos] % x != 0) {
                query(2 * pos, beg, end, l, mid, x, cnt);
            } else if (seg[2 * pos + 1] % x != 0) {
                query(2 * pos + 1, beg, end, mid + 1, r, x, cnt);
            }
            return;
        }
    }

    if (cnt >= 2) {
        return;
    }

    lli mid = (l + r) / 2;
    query(2 * pos, beg, end, l, mid, x, cnt);
    query(2 * pos + 1, beg, end, mid + 1, r, x, cnt);
}

void solve() {
    lli n, a;
    cin >> n;
    seg.resize(4 * n + 2, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    build(1, 0, n - 1);

    lli q, l, r, in, x;
    cin >> q;
    while (q--) {
        cin >> in;
        if (in == 1) {
            cin >> l >> r >> x;
            l--;
            r--;
            lli cnt = 0;
            query(1, l, r, 0, n - 1, x, cnt);
            if (cnt >= 2) {
                cout << "NO" << endln;
            } else {
                cout << "YES" << endln;
            }
        } else {
            lli i, y;
            cin >> i >> y;
            i--;
            update(1, i, y, 0, n - 1);
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