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

void solve() {
    lli n, a, b, c, d, x, y, x1, x2, y1, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    lli val = min(a, b);
    a -= val;
    b -= val;
    lli diffx = max(x - x1, x2 - x);

    if (diffx == 0 && val != 0) {
        cout << "No" << endl;
        return;
    }
    lli p = max(a, b);

    if (a == 0) {
        if (x2 - x < b) {
            cout << "No" << endl;
            return;
        }
    } else {
        if (x - x1 < a) {
            cout << "No" << endl;
            return;
        }
    }

    // if (diffx < p) {
    //     cout << "No" << endl;
    //     return;
    // }

    val = min(c, d);
    c -= val;
    d -= val;
    lli diffy = max(y2 - y, y - y1);
    if (diffy == 0 && val != 0) {
        cout << "No" << endl;
        return;
    }
    p = max(c, d);

    if (c == 0) {
        if (y2 - y < d) {
            cout << "No" << endl;
            return;
        }
    } else {
        if (y - y1 < c) {
            cout << "No" << endl;
            return;
        }
    }

    // if (diffy < p) {
    //     cout << "No" << endl;
    //     return;
    // }
    cout << "Yes" << endl;
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