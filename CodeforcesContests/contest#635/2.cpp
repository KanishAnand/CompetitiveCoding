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

void solve() {
    lli n, a, m, x;
    cin >> x >> n >> m;
    while (n > 0) {
        lli val1 = x / 2;
        val1 += 10;
        if (val1 < x) {
            n--;
            x = val1;
        } else {
            break;
        }
    }

    while (m > 0) {
        x -= 10;
        m--;
    }
    // while (x > 0) {
    //     if (n == 0 && m == 0) {
    //         break;
    //     } else if (n == 0) {
    //         x -= 10;
    //         m--;
    //     } else if (m == 0) {
    //         x = x / 2;
    //         x += 10;
    //         n--;
    //     } else {
    //         lli val1 = x / 2;
    //         val1 += 10;
    //         lli val2 = x - 10;
    //         if (val1 <= val2) {
    //             x = val1;
    //             n--;
    //         } else {
    //             x = val2;
    //             m--;
    //         }
    //         // if (n > 0) {
    //         //     x = x / 2;
    //         //     x += 10;
    //         //     n--;
    //         // } else if (m > 0) {
    //         //     x -= 10;
    //         //     m--;
    //         // }
    //     }
    // }
    if (x > 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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