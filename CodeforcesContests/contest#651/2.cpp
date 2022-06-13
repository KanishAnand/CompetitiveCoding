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
    vector<lli> even, odd;

    for (lli i = 0; i < 2 * n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            even.pb(i + 1);
        } else {
            odd.pb(i + 1);
        }
    }

    lli cnt = 0;

    if (sz(even) > 1) {
        for (lli j = 0; j < sz(even); j += 2) {
            if (sz(even) - j <= 1) {
                break;
            }
            cout << even[j] << " " << even[j + 1] << endl;
            cnt++;
            if (cnt == n - 1) {
                return;
            }
        }
    }

    if (sz(odd) > 1) {
        for (lli j = 0; j < sz(odd); j += 2) {
            if (sz(odd) - j <= 1) {
                break;
            }
            cout << odd[j] << " " << odd[j + 1] << endl;
            cnt++;
            if (cnt == n - 1) {
                break;
            }
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