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

struct cs {
    lli t, l, r;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t;
    cin >> t;
    while (t--) {
        lli m;
        vector<struct cs> v;
        cin >> n >> m;
        fr(i, 0, n) {
            struct cs st;
            cin >> st.t >> st.l >> st.r;
            v.pb(st);
        }

        lli l = v[n - 1].l, r = v[n - 1].r, t = v[n - 1].t;
        // if(n == 1){
        //     l -=
        // }

        lli flag = 0;
        for (lli i = n - 2; i >= 0; i--) {
            // lli vall = v[i].l, valr = v[i].r, valt = v[i].t;
            lli val = abs(t - v[i].t);
            l -= val;
            r += val;
            t = v[i].t;

            if (v[i].l <= l && v[i].r >= l && v[i].r <= r) {
                r = v[i].r;
            } else if (v[i].l >= l && v[i].r <= r) {
                l = v[i].l;
                r = v[i].r;
            } else if (v[i].l >= l && v[i].l <= r && v[i].r >= r) {
                l = v[i].l;
            } else if (v[i].l <= l && v[i].r >= r) {
            } else {
                flag = 1;
                break;
            }
        }

        lli val = v[0].t;
        // check
        l -= val;
        r += val;
        if (flag == 1) {
            cout << "NO" << endl;
        } else {
            if (m >= l && m <= r) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    rt;
}
