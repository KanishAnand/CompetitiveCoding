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
    lli n, a, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<lli> v, p;
        fr(i, 0, n) {
            cin >> a;
            v.pb(a);
            p.pb(a);
        }
        lli flag = 0, cnt = -0;
        lli mx = -1, mn = 1e10;
        fr(i, 0, n) {
            flag = 0;
            if (v[i] != -1) {
                if (i != 0 && v[i - 1] == -1) {
                    flag = 1;
                }
                if (i != n - 1 && v[i + 1] == -1) {
                    flag = 1;
                }
                if (flag == 1) {
                    if (v[i] > mx) {
                        mx = v[i];
                    }
                    if (v[i] < mn) {
                        mn = v[i];
                    }
                }
            } else {
                ++cnt;
            }
        }
        if (cnt == n) {
            cout << "0 0" << endl;
            continue;
        } else if (cnt == n - 1) {
            lli val;
            fr(i, 0, n) {
                if (v[i] != -1) {
                    val = v[i];
                    break;
                }
            }
            cout << "0"
                 << " " << val << endl;
            continue;
        }
        // lli val = mn + mx / 2;
        // fr(i, 0, n) {
        //     if (v[i] == -1) {
        //         v[i] = val;
        //     }
        // }
        // lli mm = -1;
        // fr(i, 1, n) {
        //     lli d = abs(v[i] - v[i - 1]);
        //     if (d > mm) {
        //         mm = d;
        //     }
        // }
        // cout << mm << " " << val << endl;
        lli beg = mn, end = mx, mm = -1, st, ans = 1e10;
        // cout << beg << " " << end << endl;
        while (beg <= end) {
            lli mid = (beg + end) / 2, mm = -1;
            fr(i, 0, n) {
                if (v[i] == -1) {
                    p[i] = mid;
                }
            }

            fr(i, 1, n) {
                lli d = abs(p[i] - p[i - 1]);
                if (d > mm) {
                    mm = d;
                }
            }
            if (mm <= ans) {
                ans = mm;
                st = mm;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        cout << st << " " << beg << endl;
    }
    rt;
}