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

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % MOD;
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

lli solve() {
    lli n, h, a;
    cin >> h >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli mn = 1e10, val = 0;
    for (lli i = 0; i < n; i++) {
        val += v[i];
        mn = min(val, mn);
    }

    if (mn >= 0) {
        cout << "-1" << endl;
        rt;
    }

    if (abs(mn) >= h) {
        for (lli i = 0; i < n; i++) {
            h += v[i];
            if (h <= 0) {
                cout << i + 1 << endl;
                break;
            }
        }
        rt;
    }

    if (val >= 0) {
        cout << "-1" << endl;
        rt;
    }

    lli de = h;
    lli p = h - abs(mn);
    lli ans = p / abs(val);
    de -= ans * abs(val);
    lli pr = ans * n, beg = 0;

    while (de > 0) {
        de += v[beg % n];
        beg++;
        pr++;
    }
    cout << pr << endl;

    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}