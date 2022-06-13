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
    lli n, a, t, b;
    cin >> t;
    while (t--) {
        lli m, sum = 0;
        vector<lli> v;
        vector<lli> cnt(62, 0);
        vector<lli> trans(62, 0);
        cin >> n >> m;
        fr(i, 0, m) {
            cin >> a;
            sum += a;
            v.pb(a);
            lli val = log2(a);
            cnt[val]++;
        }
        if (sum < n) {
            cout << "-1" << endl;
            continue;
        }
        if (sum == n) {
            cout << "0" << endl;
            continue;
        }

        lli ans = 0;
        for (lli i = 60; i >= 0; i--) {
            lli val = pow(2, i);
            // if (n >= val) {
            a = cnt[i];
            b = n / val;
            lli p = min(a, b);
            n -= p * val;
            cnt[i] -= p;
            lli tt = cnt[i] * 2;
            // cout << cnt[i] << " " << i << endl;
            trans[i] = cnt[i];
            if (i != 0) {
                ans += cnt[i];
                cnt[i - 1] += tt;
                cnt[i] = 0;
            }
            // }
            // if (n == 0) {
            //     break;
            // }
        }
        // cout << ans << endl;
        // cout << cnt[0] << endl;
        for (lli i = 0; i < 60; i++) {
            lli val = cnt[i];
            lli val2 = trans[i + 1];
            // cout << val << " " << val2 << endl;
            lli p = min(val, val2 * 2);
            // cout << p << endl;
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] -= p;
            ans -= p / 2;
            // cout << cnt[0] << endl;
            // cout << cnt[1] << endl;
        }
        cout << ans << endln;
    }
    rt;
}