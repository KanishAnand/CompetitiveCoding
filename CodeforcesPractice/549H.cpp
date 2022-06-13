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

void solve() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * d == b * c) {
        cout << "0" << endln;
        return;
    }

    bool flag = 1;  // pos
    if (a * d < b * c) {
        flag = 0;
    }

    double beg = 0, end = 1e9;
    double ans;
    long double eps = 1e-10;

    while (beg <= end) {
        double mid = (beg + end) / 2;

        double val11 = (a + mid) * (d + mid);
        double val12 = (a + mid) * (d - mid);
        double val13 = (a - mid) * (d + mid);
        double val14 = (a - mid) * (d - mid);

        double val21 = (c + mid) * (b + mid);
        double val22 = (c + mid) * (b - mid);
        double val23 = (c - mid) * (b + mid);
        double val24 = (c - mid) * (b - mid);

        if (flag == 1) {
            double p1 = min({val11, val12, val13, val14});
            double p2 = max({val21, val22, val23, val24});
            if (p1 <= p2) {
                end = mid - eps;
                ans = mid;
            } else {
                beg = mid + eps;
            }
        } else {
            double p1 = max({val11, val12, val13, val14});
            double p2 = min({val21, val22, val23, val24});
            if (p1 >= p2) {
                end = mid - eps;
                ans = mid;
            } else {
                beg = mid + eps;
            }
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}