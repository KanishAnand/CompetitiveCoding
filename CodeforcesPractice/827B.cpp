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
    lli n, k;
    cin >> n >> k;
    lli ans = (n - 1) / k;
    ans *= 2;

    lli len = (n - 1) / k;
    lli mod = (n - 1) % k;

    if (mod >= 2) {
        ans += 2;
    } else if (mod == 1) {
        ans++;
    }

    cout << ans << endln;
    lli v = 2;
    for (lli i = 0; i < k; i++) {
        lli prev = 1;
        for (lli j = 0; j < len; j++) {
            cout << prev << " " << v << endln;
            prev = v;
            v++;
        }
        if (mod != 0) {
            mod--;
            cout << prev << " " << v << endln;
            prev = v;
            v++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}