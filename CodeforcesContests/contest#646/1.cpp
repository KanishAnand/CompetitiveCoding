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
    lli n, a, x;
    cin >> n >> x;

    lli even = 0, odd = 0;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    if (odd == 0) {
        cout << "NO" << endl;
        return;
    }

    if (x == 1) {
        cout << "YES" << endl;
        return;
    }

    if (x % 2 == 0) {
        if (even == 0) {
            cout << "NO" << endl;
            return;
        }
        even--;
        odd--;
        lli no = even + ((odd / 2) * 2);
        if (no >= x - 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        odd--;
        lli no = ((odd / 2) * 2) + even;
        if (no >= x - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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