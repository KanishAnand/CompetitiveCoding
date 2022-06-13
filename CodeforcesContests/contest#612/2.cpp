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
    lli n, a, k;
    vector<string> v;
    cin >> n >> k;
    unordered_map<string, lli> mp;
    string st;

    fr(i, 0, n) {
        cin >> st;
        mp[st]++;
        v.pb(st);
    }
    lli ans = 0;

    fr(i, 0, n - 2) {
        mp[v[i]]--;
        fr(j, i + 1, n) {
            mp[v[j]]--;
            string str = "";
            fr(p, 0, k) {
                if (v[i][p] == v[j][p]) {
                    str += v[i][p];
                } else {
                    if (v[i][p] != 'S' && v[j][p] != 'S') {
                        str += 'S';
                    } else if (v[i][p] != 'E' && v[j][p] != 'E') {
                        str += 'E';
                    } else {
                        str += 'T';
                    }
                }
            }
            if (mp[str] != 0) {
                ans++;
            }
        }
        fr(j, i + 1, n) {
            mp[v[j]]++;
        }
    }
    cout << ans << endl;
    rt;
}
