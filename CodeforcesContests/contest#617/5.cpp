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
    vector<lli> v(27, -2);
    cin >> n;
    vector<lli> col(n + 2, -1);
    string st;
    cin >> st;
    fr(i, 0, n) {
        lli val = st[i] - 'a';
        v[val] = i;
    }
    lli br = 0;
    lli p = 0;

    fr(i, 0, 26) {
        lli flag = 0;
        for (lli j = 0; j < p; j++) {
            if (st[j] - 'a' > i) {
                flag = 1;
            }
            if (st[j] - 'a' == i && flag == 1) {
                br = 1;
                break;
            }
        }
        if (br == 1) {
            break;
        }

        for (lli j = p; j <= v[i]; j++) {
            if (st[j] - 'a' == i) {
                col[j] = 1;
            } else {
                col[j] = 0;
            }
        }
        if (v[i] != -2) {
            p = max(p, v[i] + 1);
        }
    }

    if (br == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        fr(i, 0, n) {
            cout << col[i];
        }
        cout << endl;
    }
    rt;
}
