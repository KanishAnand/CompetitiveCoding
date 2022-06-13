#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
    lli x, y;
    cin >> x >> y;
    string st;
    cin >> st;
    lli l = 0, r = 0, u = 0, d = 0;

    for (lli i = 0; i < len(st); i++) {
        if (st[i] == 'L') {
            l++;
        } else if (st[i] == 'R') {
            r++;
        } else if (st[i] == 'D') {
            d++;
        } else {
            u++;
        }
    }

    lli flag = 1;
    if (x < 0 && abs(x) > l) {
        flag = 0;
    }
    if (x > 0 && abs(x) > r) {
        flag = 0;
    }
    if (y < 0 && abs(y) > d) {
        flag = 0;
    }
    if (y > 0 && abs(y) > u) {
        flag = 0;
    }

    if (flag == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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