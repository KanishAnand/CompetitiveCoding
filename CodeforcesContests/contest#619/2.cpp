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
        lli mx = -1, ans;
        cin >> n;
        vector<lli> v;
        fr(i, 0, n) {
            cin >> a;
            v.pb(a);
        }
        lli flag = 0, prev = -1, cnt = 0;
        fr(i, 0, n) {
            if (v[i] != -1) {
                if (flag == 1 && prev != -1) {
                    flag = 0;
                    lli val = (v[i] + prev) / 2;
                    a = abs(val - prev);
                    b = abs(val - v[i]);
                    prev = v[i];
                    lli c = max(a, b);
                    if (c > mx) {
                        mx = c;
                        ans = val;
                    }
                    // cout << val << " " << c << endl;
                }
                prev = v[i];
                flag = 0;
            } else {
                ++cnt;
                flag = 1;
            }
        }
        // cout << ans << endl;
        if (cnt == n) {
            cout << "0 0" << endl;
        } else if (cnt == n - 1) {
            cout << "0 " << prev << endl;
        } else {
            lli mm = 0;
            fr(i, 0, n) {
                if (v[i] == -1) {
                    v[i] = ans;
                }
            }
            fr(i, 1, n) {
                lli d = abs(v[i] - v[i - 1]);
                if (d > mm) {
                    mm = d;
                    v[i] - v[i - 1];
                }
            }
            cout << mm << " " << ans << endl;
        }
    }
    rt;
}
