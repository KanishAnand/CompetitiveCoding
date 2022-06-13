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
        lli sum = n - 1, sum2 = n + 1;
        lli arr[n][n];
        fr(i, 0, n) {
            fr(j, 0, n) {
                if (i == j) {
                    arr[i][j] = 1;
                    continue;
                }
                arr[i][j] = 0;
            }
        }
        if (n == 1) {
            cout << "Hooray" << endl;
            cout << "1" << endl;
        } else if (n % 2 == 1) {
            cout << "Boo" << endl;
        } else {
            cout << "Hooray" << endl;
            fr(i, 0, n) {
                arr[0][i] = i + 1;
            }
            fr(i, 2, n - 1) {
                lli val = arr[0][i] + 1;
                lli ind = 1;
                while (arr[ind][i] != 1) {
                    arr[ind][i] = val;
                    val++;
                    if (val > n) {
                        val = 2;
                    }
                    ind++;
                }
            }

            // for last column
            if (n != 2) {
                arr[1][n - 1] = 3;
                fr(i, 2, n / 2) {
                    arr[i][n - 1] = arr[i - 1][n - 1] + 2;
                }
                for (lli i = n - 2; i >= n / 2; i--) {
                    arr[i][n - 1] = sum2 - arr[n - 1 - i][n - 1];
                }
            }

            fr(i, 0, n) {
                fr(j, 0, n) {
                    if (arr[i][j] == 0) {
                        arr[i][j] = arr[j][i] + sum;
                    }
                }
            }
            fr(i, 0, n) {
                fr(j, 0, n) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    rt;
}