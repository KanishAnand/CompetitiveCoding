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
    vector<lli> v;
    cin >> t;
    while (t--) {
        cin >> n;
        string st;
        cin >> st;
        map<lli, map<lli, lli>> mp;
        mp[0][0] = -1;
        lli x = 0, y = 0;
        lli ansl = 0, ansr = 0;
        lli ans = 1e15;
        fr(i, 0, n) {
            if (st[i] == 'U') {
                y++;
            } else if (st[i] == 'D') {
                y--;
            } else if (st[i] == 'R') {
                x++;
            } else {
                x--;
            }
            if (mp[x][y] != 0) {
                lli val;
                if (mp[x][y] != -1) {
                    val = i + 1 - mp[x][y];
                } else {
                    val = i + 1;
                }
                if (val < ans) {
                    ans = val;
                    if (mp[x][y] == -1) {
                        ansl = 1;
                    } else {
                        ansl = mp[x][y] + 1;
                    }
                    ansr = i + 1;
                }
            }
            mp[x][y] = i + 1;
        }
        if (ans != 1e15) {
            cout << ansl << " " << ansr << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    rt;
}
