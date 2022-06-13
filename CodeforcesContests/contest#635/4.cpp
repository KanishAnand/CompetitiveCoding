#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
lli ans = -1;

lli fun(vector<lli> r, vector<lli> gr, vector<lli> bl) {
    lli y, x, z;

    for (lli i = 0; i < r.size(); i++) {
        lli y = r[i];
        // cout << y << endl;
        auto it1 = lower_bound(gr.begin(), gr.end(), y);
        auto it2 = lower_bound(bl.begin(), bl.end(), y);
        lli flag1 = 0;
        // cout << *it1 << endl;

        if (it1 == gr.end() && it1 != gr.begin()) {
            it1--;
            x = *it1;
        } else {
            lli val1 = *it1;
            if (val1 == y) {
                x = val1;
            } else {
                if (it1 == gr.begin()) {
                    flag1 = 1;
                } else {
                    it1--;
                    x = *it1;
                }
            }
        }

        // cout << x << " " << y << endl;

        if (it2 == bl.end()) {
            flag1 = 1;
        } else {
            z = *it2;
        }
        // cout << z << " " << y << endl;

        if (flag1 == 0) {
            // cout << x << " " << y << " " << z << endl;
            lli val = (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z);
            if (ans == -1) {
                ans = val;
            } else {
                ans = min(ans, val);
            }
        }

        //     it1 = lower_bound(bl.begin(), bl.end(), y);
        //     it2 = lower_bound(gr.begin(), gr.end(), y);

        //     if (it1 == bl.end()) {
        //         flag2 = 1;
        //     } else {
        //         lli val1 = *it1;
        //         if (val1 == y) {
        //             x = val1;
        //         } else {
        //             if (it1 == bl.begin()) {
        //                 flag2 = 1;
        //             } else {
        //                 it1--;
        //                 x = *it1;
        //             }
        //         }
        //     }

        //     if (it2 == gr.end()) {
        //         flag2 = 1;
        //     } else {
        //         z = *it2;
        //     }

        //     if (flag2 == 0) {
        //         lli val = (x - y) * (x - y) + (y - z) * (y - z) + (x - z) *
        //         (x - z); if (ans == -1) {
        //             ans = val;
        //         } else {
        //             ans = min(ans, val);
        //         }
        //     }
        // }
    }
}

void solve() {
    lli a, b, c, p;
    ans = -1;
    cin >> a >> b >> c;
    vector<lli> r, gr, bl;

    for (lli i = 0; i < a; i++) {
        cin >> p;
        r.pb(p);
    }
    for (lli i = 0; i < b; i++) {
        cin >> p;
        gr.pb(p);
    }
    for (lli i = 0; i < c; i++) {
        cin >> p;
        bl.pb(p);
    }

    sort(all(r));
    sort(all(gr));
    sort(all(bl));

    fun(r, gr, bl);
    fun(r, bl, gr);
    fun(gr, r, bl);
    fun(gr, bl, r);
    // cout << ans << endl;
    fun(bl, r, gr);
    fun(bl, gr, r);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}