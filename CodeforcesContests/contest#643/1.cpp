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
    lli n, k;
    cin >> n >> k;
    lli no = n;
    k--;
    while (k > 0) {
        k--;
        lli tmp = no;
        lli mx = -1, mn = -1;
        lli flag = 0;
        while (tmp > 0) {
            lli rem = tmp % 10;
            if (flag == 0) {
                mx = rem;
                mn = rem;
                flag = 1;
            }
            mx = max(rem, mx);
            mn = min(rem, mn);
            tmp /= 10;
        }

        no += mx * mn;
        if (mx == 0 || mn == 0) {
            break;
        }
        // cout << no << endl;
    }
    cout << no << endl;
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