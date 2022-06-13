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
double h, c, t;

double fun(lli a) {
    lli val = (a + 1) * h + a * c - (2 * a + 1) * t;
    // cout << val << endl;
    // cout << "ka" << endl;
    lli p = 2 * a + 1;
    double c = ((double)val / (double)p);
    c = fabs(c);
    return c;
}

void solve() {
    cin >> h >> c >> t;
    double vv = (double)((h + c) / 2) - t;
    vv = fabs(vv);
    lli ans = 2;

    lli start = 0, end = 1e6;

    while ((end - start) >= 2) {
        lli mid = (start + end) / 2;
        double val1 = fun(mid - 1);
        double val2 = fun(mid);
        double val3 = fun(mid + 1);

        if (val1 >= val2 && val2 >= val3) {
            start = mid;
        } else if (val1 <= val2 && val2 <= val3) {
            end = mid;
        } else if (val1 >= val2 && val3 >= val2) {
            if (val2 <= vv) {
                vv = val2;
                // cout << val2 << endl;
                // cout << vv << endl;
                ans = mid * 2 + 1;
            }
            break;
        }
    }

    for (lli i = start; i <= end; i++) {
        double qq = fun(i);
        if (qq < vv) {
            vv = qq;
            ans = 2 * i + 1;
        }
    }

    // cout << vv << endl;
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