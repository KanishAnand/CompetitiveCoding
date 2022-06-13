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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli beg = 0;
    for (lli i = 0; i < n; i++) {
        if (v[i] == i + 1) {
            beg = i + 1;
        } else {
            break;
        }
    }

    lli end = n - 1;
    for (lli i = n - 1; i >= 0; i--) {
        if (v[i] == i + 1) {
            end = i - 1;
        } else {
            break;
        }
    }

    if (end - beg <= 0) {
        cout << "0" << endln;
        return;
    }

    lli flag = 0;
    for (lli i = beg; i <= end; i++) {
        if (v[i] == i + 1) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        cout << "1" << endln;
        return;
    }

    cout << "2" << endln;
    return;
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