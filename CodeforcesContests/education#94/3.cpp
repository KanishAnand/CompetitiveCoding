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
    lli n, x;
    string st;
    cin >> st;
    cin >> x;
    n = st.length();
    vector<lli> ans(n + 2, 1);

    for (lli i = 0; i < n; i++) {
        if (st[i] == '0') {
            if (i - x >= 0) {
                ans[i - x] = 0;
            }
            if (i + x < n) {
                ans[i + x] = 0;
            }
        }
    }

    lli flag = 0;
    for (lli i = 0; i < n; i++) {
        if (st[i] == '1') {
            lli p = 0;
            if (i - x >= 0) {
                if (ans[i - x] == 1) {
                    p = 1;
                }
            }
            if (i + x < n) {
                if (ans[i + x] == 1) {
                    p = 1;
                }
            }
            if (p == 0) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        cout << "-1" << endl;
    } else {
        for (lli i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
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