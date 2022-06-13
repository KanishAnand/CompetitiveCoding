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
    lli n, a, b, aa, bb;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << endln;
        return;
    }

    lli ans = 1e10, flag = 0;
    lli p = sqrt(n);
    for (lli i = 2; i <= p; i++) {
        if (n % i == 0) {
            flag = 1;
            a = i;
            b = n - a;
            lli lcm = (a * b) / (__gcd(a, b));
            if (lcm < ans) {
                ans = lcm;
                aa = a;
                bb = b;
            }
            a = n / i;
            b = n - a;
            lcm = (a * b) / (__gcd(a, b));
            if (lcm < ans) {
                ans = lcm;
                aa = a;
                bb = b;
            }
        }
    }

    if (flag == 0) {
        cout << "1"
             << " " << n - 1 << endln;
        return;
    }
    cout << aa << " " << bb << endln;
    // lli n, a, b, aa, bb;
    // lli ans = 1e9;
    // cin >> n;
    // for (lli i = 1; i < n; i++) {
    //     a = i;
    //     b = n - i;
    //     lli lcm = (a * b) / (__gcd(a, b));
    //     if (lcm < ans) {
    //         ans = lcm;
    //         aa = a;
    //         bb = b;
    //     }
    // }

    // cout << aa << " " << bb << endl;
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