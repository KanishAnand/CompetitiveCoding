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

double fun(lli len, lli a, lli b, lli c) {
    if (a == 0) {
        return 0;
    }

    lli val = 100 - a;
    if (val <= a) {
        lli ans = 0;
        for (lli i = 0; i <= len - val; i++) {
            if (100 - b < i && (100 - c) < (len - val - i)) {
                if ((i != 0 && b != 0) && (len - val - i != 0 && c != 0)) {
                }
            }
        }
        return ans;
    } else {
        return 0;
    }
}

void solve() {
    lli a, b, c;
    cin >> a >> b >> c;
    double ans = 0;
    for (lli i = 1; i <= 99; i++) {
        ans += fun(i, a, b, c);
        ans += fun(i, b, a, c);
        ans += fun(i, c, a, b);
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