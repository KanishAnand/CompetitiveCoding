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
    string st;
    cin >> st;
    lli m;
    cin >> m;

    lli beg = 0;
    for (lli i = 0; i < len(st); i++) {
        lli p = (st[i] - '0') + 1;
        beg = max(beg, p);
    }

    lli org_beg = beg;
    lli end = 1e18, mx = -1;
    if (len(st) == 1) {
        lli p = st[0] - '0';
        if (m >= p) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
        return;
    }

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli val = 0, p = 1, flag = 1;
        for (lli i = len(st) - 1; i >= 0; i--) {
            lli tmp = (st[i] - '0');
            if (tmp != 0) {
                tmp *= p;
                if (val > 1e18 - tmp) {
                    flag = 0;
                    break;
                }
                val += tmp;
            }
            if (i == 0) {
                break;
            }
            if (p > 1e18 / mid) {
                flag = 0;
                break;
            }
            p *= mid;
        }

        if (flag == 0 || val > m) {
            end = mid - 1;
        } else {
            mx = max(mx, mid);
            beg = mid + 1;
        }
    }
    lli ans = max(0ll, mx - org_beg + 1);
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}