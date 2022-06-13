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
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
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
    vector<lli> v;
    cin >> n;
    lli sx, sy;
    cin >> sx >> sy;
    lli x, y, box1 = 0, box2 = 0, box3 = 0, box4 = 0;
    lli x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    fr(i, 0, n) {
        cin >> x >> y;
        if (sx == x) {
            if (y > sy) {
                y1++;
            } else {
                y2++;
            }
        } else if (sy == y) {
            if (x > sx) {
                x1++;
            } else {
                x2++;
            }
        } else {
            if (x > sx) {
                if (y > sy) {
                    box2++;
                } else {
                    box4++;
                }
            } else {
                if (y > sy) {
                    box1++;
                } else {
                    box3++;
                }
            }
        }
    }

    lli ans1, ans2, ans3, ans4;
    ans1 = y1 + box1 + box2;
    ans2 = y2 + box3 + box4;
    ans3 = x1 + box2 + box4;
    ans4 = x2 + box1 + box3;
    lli p = max({ans1, ans2, ans3, ans4});

    if (ans1 == p) {
        cout << ans1 << endl;
        cout << sx << " " << sy + 1 << endl;
    } else if (ans2 == p) {
        cout << ans2 << endl;
        cout << sx << " " << sy - 1 << endl;
    } else if (ans3 == p) {
        cout << ans3 << endl;
        cout << sx + 1 << " " << sy << endl;
    } else {
        cout << ans4 << endl;
        cout << sx - 1 << " " << sy << endl;
    }
    rt;
}
