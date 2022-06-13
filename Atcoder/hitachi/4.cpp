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
vector<pair<lli, lli>> v;

// lli fun(lli a) {
//     lli time = 1;
//     fr(i, 0, a) {
//         lli val = p[i].second;
//         time += v[val].first * time + v[val].second;
//         time++;
//     }
//     return time - 1;
// }

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t, b;
    cin >> n >> t;
    struct vv {
        lli a, b, c;
    };
    vector<struct vv> p;

    fr(i, 0, n) {
        struct vv pp;
        cin >> a >> b;
        v.pb({a, b});
        pp.a = a + b;
        pp.b = -a;
        pp.c = i;
        // double x = double(a + b);
        // double y = double(a);
        // // y += double(1);
        // if (a == 0) {
        //     y += double(1);
        // }
        // double val = x / y;
        // cout << val << endl;
        p.pb(pp);
    }

    sort(all(p),
         [](auto a, auto b) { return a.a < b.a || (a.a == b.a && a.b < b.b); });
    lli time = 1, ans = -1;

    fr(i, 0, n) {
        lli val = p[i].c;

        lli x = v[val].first * time + v[val].second;

        time += x;
        if (time <= t) {
            ans = max(ans, i + 1);
        }

        time++;
    }

    // lli beg = 0, end = n, ans = -1;

    // while (beg <= end) {
    //     lli mid = (beg + end) / 2;
    //     lli tm = fun(mid);
    //     if (tm <= t) {
    //         beg = mid + 1;
    //         ans = max(ans, mid);
    //     } else {
    //         end = mid - 1;
    //     }
    // }
    cout << ans << endl;
    rt;
}