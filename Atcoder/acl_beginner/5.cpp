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
const lli MOD = 998244353;
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

lli n, store_no;
vector<lli> seg, lazy;

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return ans;
}

lli calc(lli a, lli b, lli val) {
    lli pref = power(10, n - 1 - b);

    lli no = b - a + 1;

    lli p = power(10, no);
    p--;
    p += MOD;
    p %= MOD;

    p *= store_no;
    p %= MOD;

    p *= pref;
    p %= MOD;

    p *= val;
    p %= MOD;

    return p;
}

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = calc(l, r, 1);
        return;
    }

    build(2 * pos, l, mid);
    build(2 * pos + 1, mid + 1, r);
    seg[pos] = (seg[2 * pos] + seg[2 * pos + 1]) % MOD;
    return;
}

void push(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;

    lazy[2 * pos] = lazy[pos];
    lazy[2 * pos + 1] = lazy[pos];

    seg[2 * pos] = calc(l, mid, lazy[pos]);
    seg[2 * pos] %= MOD;

    seg[2 * pos + 1] = calc(mid + 1, r, lazy[pos]);
    seg[2 * pos + 1] %= MOD;

    lazy[pos] = 0;
    return;
}

void update(lli pos, lli beg, lli end, lli val, lli l, lli r) {
    lli mid = (l + r) / 2;

    if (l > r || end < l || beg > r) {
        return;
    }

    if (l != r && lazy[pos] != 0) {
        push(pos, l, r);
    }

    if (beg <= l && end >= r) {
        lli p = calc(l, r, val);
        seg[pos] = p;
        lazy[pos] = val;
        return;
    }

    update(2 * pos, beg, end, val, l, mid);
    update(2 * pos + 1, beg, end, val, mid + 1, r);
    seg[pos] = (seg[2 * pos] + seg[2 * pos + 1]) % MOD;
    return;
}

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }

    if (l != r && lazy[pos] != 0) {
        push(pos, l, r);
    }

    if (beg <= l && end >= r) {
        return seg[pos];
    }

    lli mid = (l + r) / 2;

    return (query(2 * pos, beg, end, l, mid) +
            query(2 * pos + 1, beg, end, mid + 1, r)) %
           MOD;
}

void solve() {
    lli q;
    cin >> n >> q;

    store_no = power(9, MOD - 2);

    lli l, r, d;

    seg.resize(4 * n + 2, 0);
    lazy.resize(4 * n + 2, 0);

    build(1, 0, n - 1);

    for (lli i = 0; i < q; i++) {
        cin >> l >> r >> d;
        l--;
        r--;
        update(1, l, r, d, 0, n - 1);
        lli ans = query(1, 0, n - 1, 0, n - 1);
        cout << ans << endl;
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