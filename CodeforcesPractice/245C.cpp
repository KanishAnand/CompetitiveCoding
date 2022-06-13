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
    v.pb(0);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    if (n <= 2 || n % 2 == 0) {
        cout << "-1" << endl;
        return;
    }

    lli ans = 0;

    for (lli i = n; i >= 3; i -= 2) {
        lli val = max(v[i], v[i - 1]);
        ans += val;
        v[i] -= val;
        v[i - 1] -= val;
        v[(i - 1) / 2] -= val;
        v[i] = max(v[i], 0ll);
        v[i - 1] = max(v[i - 1], 0ll);
        v[(i - 1) / 2] = max(v[(i - 1) / 2], 0ll);
    }

    for (lli i = 1; i <= n; i++) {
        ans += v[i];
    }

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