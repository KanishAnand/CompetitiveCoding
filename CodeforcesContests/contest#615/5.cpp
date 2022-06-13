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
    lli n, a, m;
    cin >> n >> m;
    vector<set<pair<lli, lli>>> v;
    lli arr[m + 2][n + 2];

    v.resize(m + 2);
    for (lli i = 0; i < m; i++) {
        for (lli j = 0; j < n; j++) {
            v[i].insert({j + n, j});
            arr[i][j] = j + n;
        }
    }

    fr(i, 0, n) {
        fr(j, 0, m) {
            cin >> a;
            // cout << i << " " << j << endl;
            if (a <= n * m && a % m == (j + 1) % m) {
                lli p = a / m;
                if (a % m == 0) {
                    p--;
                }
                lli val = i - p;
                if (val < 0) {
                    val += n;
                }
                lli cnt = arr[j][val];
                // cout << p << " " << val << " " << cnt << " " << i << " " << j
                //      << endl;
                auto it = v[j].find({cnt, val});
                if (it != v[j].end()) {
                    v[j].erase(it);
                    // cout << "K" << endl;
                    v[j].insert({cnt - 1, val});
                    arr[j][val] -= 1;
                }
                // cout << arr[j][val] << endl;
            }
        }
    }

    lli ans = 0;
    fr(i, 0, m) {
        auto it = v[i].begin();
        ans += (*it).first;
    }
    cout << ans << endl;

    rt;
}
