#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, k, p;
    vector<lli> v;
    cin >> n >> a >> b >> k;
    lli sum = a + b;
    fr(i, 0, n) {
        cin >> p;
        lli val = p % sum, q;
        if (val == 0) {
            q = a + b;
        } else {
            q = val;
        }
        if (q - a <= 0) {
            v.pb(0);
        } else {
            q -= a;
            lli vl = q / a;
            if (q % a != 0) {
                vl += 1;
            }
            v.pb(vl);
        }
    }
    sort(all(v));
    lli s = 0, ans = 0;
    fr(i, 0, n) {
        s += v[i];
        if (s <= k) {
            ans = i + 1;
        }
    }
    cout << ans << endl;

    rt;
}
