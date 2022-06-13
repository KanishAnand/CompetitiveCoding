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

lli query(lli pos, lli beg, lli end, lli l, lli r) {
    if (l > r || end < l || beg > r) {
        return 0;
    }
    if (beg <= l && end >= r) {
        return seg[pos];
    }
    lli mid = (l + r) / 2;
    return __gcd(query(2 * pos, beg, end, l, mid),
                 query(2 * pos + 1, beg, end, mid + 1, r));
}

void solve() {
    v.clear();
    seg.clear();

    lli n, a;
    cin >> n;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        v.pb(v[i]);
    }

    seg.resize(8 * n + 2, 0);
    build(1, 0, 2 * n - 1);

    lli beg = 0, end = n, ans = n;
    while (beg <= end) {
        lli mid = (beg + end) / 2;

        set<lli> st;
        for (lli i = 0; i < n; i++) {
            lli val = query(1, i, i + mid, 0, 2 * n - 1);
            st.insert(val);
        }

        if (sz(st) != 1) {
            beg = mid + 1;
        } else {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}