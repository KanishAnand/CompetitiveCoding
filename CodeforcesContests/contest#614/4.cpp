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
    lli n, a, x0, y0, ax, ay, bx, by, sx, sy, t, b;
    vector<pair<lli, lli>> v;
    vector<lli> p;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> sx >> sy >> t;
    a = x0;
    b = y0;
    lli val = 60;
    fr(i, 0, val) {
        p.pb(a);
        v.pb({a, b});
        a = ax * a + bx;
        b = ay * b + by;
    }
    sort(all(v));
    sort(all(p));
    cout << p[0] << endl;
    auto it = upper_bound(p.begin(), p.end(), sx);
    it--;
    lli ind = it - p.begin();
    lli ans = 0, tm = 0;
    a = sx, b = sy;
    while (t > 0 || ind >= 0) {
        lli x = v[ind].first;
        lli y = v[ind].second;
        tm = abs(x - a) + abs(y - b);
        if (t - tm >= 0) {
            a = x;
            b = y;
            ind--;
            ans++;
            t -= tm;
        } else {
            t = 0;
            break;
        }
    }
    if (t == 0) {
        cout << ans << endl;
        rt;
    }
    ind++;
    lli x = v[ind].first;
    lli y = v[ind].second;
    tm = abs(x - a) + abs(y - b);
    if (tm < t) {
        cout << ans << endl;
        rt;
    } else {
        ind++;
        t -= tm;
        ans++;
        while (t > 0) {
            lli x = v[ind].first;
            lli y = v[ind].second;
            tm = abs(x - a) + abs(y - b);
            if (t - tm >= 0) {
                a = x;
                b = y;
                ind++;
                ans++;
                t -= tm;
            } else {
                t = 0;
                break;
            }
        }
    }
    cout << ans << endl;
    rt;
}