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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

lli check(lli a, lli d) {
    while (a > 0) {
        lli rem = a % 10;
        if (rem == d) {
            return 1;
        }
        a /= 10;
    }
    return 0;
}

void solve() {
    lli n, d, a;
    cin >> n >> d;
    lli val = d + d * 10;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (check(a, d) == 1) {
            cout << "YES" << endl;
        } else if (a >= val) {
            cout << "YES" << endl;
        } else {
            lli flag = 0;
            a -= d;
            while (a >= 0) {
                if (check(a, d) == 1) {
                    flag = 1;
                    break;
                }
                a -= d;
            }
            if (flag == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
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