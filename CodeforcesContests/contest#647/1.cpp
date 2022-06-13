#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli unsigned long long int
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

void solve() {
    lli n, a, b;
    cin >> a >> b;
    lli ans = 0;
    if (a > b) {
        while (b * 8 <= a) {
            b *= 8;
            ans++;
        }
        while (b * 4 <= a) {
            b *= 4;
            ans++;
        }
        while (b * 2 <= a) {
            b *= 2;
            ans++;
        }
    } else {
        while (a * 8 <= b) {
            a *= 8;
            ans++;
        }
        while (a * 4 <= b) {
            a *= 4;
            ans++;
        }
        while (a * 2 <= b) {
            a *= 2;
            ans++;
        }
    }

    if (a != b) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
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