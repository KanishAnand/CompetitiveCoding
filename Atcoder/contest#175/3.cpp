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
    lli x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    lli val = x / d;
    if (k <= val) {
        lli ans = abs(x - k * d);
        cout << ans << endl;
    } else {
        x -= val * d;
        k -= val;
        lli no1 = x;
        lli no2 = abs(x - d);

        if (no1 <= no2) {
            if (k % 2 == 0) {
                cout << no1 << endl;
            } else {
                cout << no2 << endl;
            }
        } else {
            k--;
            if (k % 2 == 0) {
                cout << no2 << endl;
            } else {
                cout << no1 << endl;
            }
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