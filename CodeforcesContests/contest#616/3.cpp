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
        lli m, k;
        vector<lli> v;
        cin >> n >> m >> k;
        fr(i, 0, n) {
            cin >> a;
            v.pb(a);
        }
        lli ans = -1;
        // change the max value of k
        lli q = min(k, m - 1);

        for (lli val = 0; val <= q; val++) {
            // cout << "df" << endl;
            lli cnt = 1;
            vector<lli> arr, rr;
            lli rem = q - val;
            for (lli j = val; j < m; j++) {
                lli p = max(v[j], v[n - (m - 1 - j) - 1]);
                // cout<<cnt<<" "<<rem<<endl;
                if (m - 1 - j >= rem) {
                    arr.pb(p);
                }
                // rr.pb(p);
                // cout << p << endl;
                // ++cnt;
            }
            // cout << arr.size() << endl;
            if (arr.size() != 0) {
                sort(all(arr));
                if (arr[0] > ans) {
                    ans = arr[0];
                }
            }
            //  else {
            //     sort(all(rr));
            //     lli tt = rr.size() - 1;
            //     if (rr[tt] > ans) {
            //         ans = rr[tt];
            //     }
            // }
            // cout << arr[0] << endl;
        }
        cout << ans << endl;
    }
    rt;
}
