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

vector<lli> seg, v;

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
    seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
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
    return max(query(2 * pos, beg, end, l, mid),
               query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    lli n, a, k;
    cin >> n >> k;
    vector<lli> store;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        store.pb(a);
    }

    lli lim = 300000;
    seg.resize(4 * lim + 2, 0);
    v.resize(lim + 2, 0);

    for (lli i = 0; i < n; i++) {
        lli mn = store[i] - k;
        mn = max(mn, 0ll);
        lli mx = store[i] + k;
        mx = min(mx, lim);

        lli val = query(1, mn, mx, 0, lim);
        if (v[store[i]] < val + 1) {
            update(1, store[i], val + 1, 0, lim);
        }
    }

    lli ans = query(1, 0, lim, 0, lim);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}