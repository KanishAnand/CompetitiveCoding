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
    lli n, a, b;
    cin >> n;
    vector<pair<lli, lli>> v;

    lli cost = 0, mn = 1e14;
    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({a, b});
    }

    if (n == 1) {
        cout << v[0].first << endl;
        return;
    }

    for (lli i = 0; i < n; i++) {
        if (i == 0) {
            lli val = v[i].first - v[n - 1].second;
            if (val > 0) {
                cost += val;
                v[i].first -= val;
            }
            mn = min(mn, v[i].first);
        } else {
            lli val = v[i].first - v[i - 1].second;
            if (val > 0) {
                cost += val;
                v[i].first -= val;
            }
            mn = min(mn, v[i].first);
        }
    }

    cout << mn + cost << endl;
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