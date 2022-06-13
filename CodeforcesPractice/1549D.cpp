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

vector<lli> seg, diff;

void build(lli pos, lli l, lli r) {
    lli mid = (l + r) / 2;
    if (l > r) {
        return;
    } else if (l == r) {
        seg[pos] = diff[l];
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
    seg.clear();
    diff.clear();

    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    if (n == 1) {
        cout << "1" << endl;
        return;
    }

    for (lli i = 1; i < n; i++) {
        diff.pb(abs(v[i] - v[i - 1]));
    }

    seg.resize(4 * n + 2, 0);
    build(1, 0, n - 2);

    lli beg = 0, end = 0, ans = 0;
    for (lli beg = 0; beg < sz(diff); beg++) {
        end = max(beg, end);
        for (lli j = end; j < sz(diff); j++) {
            lli res = query(1, beg, j, 0, n - 2);
            if (res == 1) {
                break;
            }
            end = j;
            ans = max(ans, j - beg + 1);
        }
    }

    ans++;
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