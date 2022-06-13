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
const long double PI = 2 * acos(0.0);
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

lli roundd(long double a) {
    if (abs(a) < 1e-9) {
        return 0;
    }
    if (a >= 0) {
        return floor(a);
    } else {
        return ceil(a);
    }
}

void solve() {
    long double x, y, r;
    cin >> x >> y >> r;

    lli ans = 0;
    lli ll = roundd(x - r), rr = roundd(x + r);

    for (lli i = ll; i <= rr; i++) {
        long double p = i;
        p = p - x;
        long double val = r * r - p * p;

        long double rhs = sqrt(val);
        long double lhs1 = min(y + rhs, y - rhs);
        long double lhs2 = max(y + rhs, y - rhs);

        lli a = roundd(lhs1), b = roundd(lhs2);

        long double aa = a;
        long double bb = b;
        long double val1 = (x - i) * (x - i) + (y - aa) * (y - aa);
        long double val2 = (x - i) * (x - i) + (y - bb) * (y - bb);

        if (abs(val1 - r * r) > 1e-9 && val1 > r * r) {
            a++;
        }

        if (abs(val2 - r * r) > 1e-9 && val2 > r * r) {
            b--;
        }

        // cout << i << " " << a << " " << b << endl;
        ans += max(b - a + 1, 0ll);
    }

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