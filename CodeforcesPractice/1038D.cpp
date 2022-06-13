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

void solve() {
    lli n, a, neg = 0, pos = 0, sum = 0;
    cin >> n;
    vector<lli> v;
    fr(i, 0, n) {
        cin >> a;
        sum += abs(a);
        if (a < 0) {
            neg++;
        } else {
            pos++;
        }
        v.pb(a);
    }
    if (n == 1) {
        cout << v[0] << endl;
        return;
    }

    if (neg != 0 && pos != 0) {
        cout << sum << endl;
    } else if (neg == 0) {
        lli mn = 1e18 + 5;
        fr(i, 0, n - 1) {
            lli val = v[i] + v[i + 1] - abs(v[i] - v[i + 1]);
            mn = min(mn, val);
        }
        cout << sum - mn << endl;
    } else {
        lli mn = 1e18 + 5;
        fr(i, 0, n - 1) {
            lli val = -v[i] - v[i + 1] - abs(v[i] - v[i + 1]);
            mn = min(mn, val);
        }
        cout << sum - mn << endl;
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