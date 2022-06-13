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
    lli n, k;
    cin >> n >> k;

    lli mx = (n - 1) / 2;
    if (k > mx) {
        cout << "-1" << endl;
        return;
    }

    vector<lli> v(n, -1);

    lli no = n;
    for (lli i = 1; i < n; i += 2) {
        if (k == 0) {
            break;
        }
        v[i] = no;
        no--;
        k--;
    }

    for (lli i = 0; i < n; i++) {
        if (v[i] != -1) {
            continue;
        }
        v[i] = no;
        no--;
    }

    for (lli i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
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