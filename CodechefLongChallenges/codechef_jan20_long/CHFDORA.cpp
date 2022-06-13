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
    lli n, a, t, m;
    cin >> t;
    while (t--) {
        vector<vector<lli>> v;
        cin >> n >> m;
        v.resize(n + 2);
        fr(i, 0, n) {
            fr(j, 0, m) {
                cin >> a;
                v[i].pb(a);
            }
        }

        lli ans = 0;

        fr(i, 0, n) {
            fr(j, 0, m) {
                lli val1 = i;
                lli val2 = n - 1 - i;
                lli val3 = j;
                lli val4 = m - 1 - j;
                lli p = min({val1, val2, val3, val4});
                lli len1 = 0;
                while (len1 < p) {
                    if (v[i - (len1 + 1)][j] == v[i + len1 + 1][j]) {
                        len1++;
                    } else {
                        break;
                    }
                }
                lli len2 = 0;
                while (len2 < p) {
                    if (v[i][j - (len2 + 1)] == v[i][j + len2 + 1]) {
                        len2++;
                    } else {
                        break;
                    }
                }
                ans++;
                ans += min(len1, len2);
            }
        }
        cout << ans << endl;
    }
    rt;
}
