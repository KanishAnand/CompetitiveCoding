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
    vector<lli> va, vb;
    lli mna = 1e10, mnb = 1e10;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mna = min(mna, a);
        va.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mnb = min(mnb, a);
        vb.pb(a);
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        lli val1 = va[i] - mna;
        lli val2 = vb[i] - mnb;
        lli p = min(val1, val2);
        val1 -= p;
        val2 -= p;
        ans += p;
        ans += (val1 + val2);
    }

    cout << ans << endl;
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