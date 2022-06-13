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
    lli n, a;
    vector<lli> v;
    cin >> n;
    lli p = 0, od;
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
        if (a % 2 == 1) {
            p++;
        }
    }

    lli tot = n / 2 + n % 2;
    od = tot - p;
    // cout << od << endl;
    lli dp[n + 3][n + 3][2];
    for (lli i = 0; i < n + 3; i++) {
        for (lli j = 0; j < n + 3; j++) {
            dp[i][j][0] = 1e11;
            dp[i][j][1] = 1e11;
        }
    }

    lli cnt = 0;
    // cout << od << endl;
    // base case
    if (v[0] == 0) {
        dp[0][0][0] = 0;
        dp[0][1][1] = 0;
    } else {
        dp[0][0][v[0] % 2] = 0;
    }

    for (lli i = 1; i < n; i++) {
        if (v[i] != 0) {
            if (v[i - 1] == 0) {
                for (lli j = 0; j <= n; j++) {
                    dp[i][j][v[i] % 2] = min(dp[i - 1][j][v[i] % 2],
                                             dp[i - 1][j][1 - (v[i] % 2)] + 1);
                }
            } else {
                for (lli j = 0; j <= n; j++) {
                    if (v[i] % 2 != v[i - 1] % 2) {
                        dp[i][j][v[i] % 2] = dp[i - 1][j][v[i - 1] % 2] + 1;
                    } else {
                        dp[i][j][v[i] % 2] = dp[i - 1][j][v[i - 1] % 2];
                    }
                }
            }
        } else {
            if (v[i - 1] != 0) {
                for (lli j = 0; j <= n; j++) {
                    if (v[i - 1] % 2 == 0) {
                        dp[i][j][0] = dp[i - 1][j][0];
                        if (j != 0) {
                            dp[i][j][1] = dp[i - 1][j - 1][0] + 1;
                        }
                    } else {
                        if (j != 0) {
                            dp[i][j][1] = dp[i - 1][j - 1][1];
                        }
                        dp[i][j][0] = dp[i - 1][j][1] + 1;
                    }
                }
            } else {
                for (lli j = 0; j <= n; j++) {
                    if (j != 0) {
                        dp[i][j][1] =
                            min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0] + 1);
                    }
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
                }
            }
        }
    }

    lli mn = 1e10;
    // cout << od << " " << n - 1 << endl;
    lli ans = min(dp[n - 1][od][0], dp[n - 1][od][1]);
    cout << ans << endl;

    rt;
}
