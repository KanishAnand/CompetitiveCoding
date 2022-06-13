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
    lli n, l, r;
    cin >> n;
    vector<lli> left, right;

    vector<pair<lli, lli>> v;
    for (lli i = 0; i < n; i++) {
        cin >> l >> r;
        left.pb(l);
        right.pb(r);
        v.pb({l, r});
    }

    sort(all(v));
    sort(all(left));
    sort(all(right));

    lli ans = n;

    for (auto pr : v) {
        lli val = 0;
        l = pr.first;
        r = pr.second;

        auto it = lower_bound(right.begin(), right.end(), l);
        lli ind = it - right.begin();
        val += ind;

        auto itt = upper_bound(left.begin(), left.end(), r);
        if (itt == left.end()) {
            ind = 0;
        } else {
            ind = left.end() - itt;
        }
        val += ind;

        ans = min(ans, val);
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