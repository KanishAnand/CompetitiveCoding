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
    lli n, a;
    cin >> n;
    vector<pair<lli, lli>> v(n);

    for (lli i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (lli i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    sort(all(v));

    if (v[0].first != 1) {
        v.pb({1, 1});
        sort(all(v));
    }

    lli ans = 0, r1, c1, r2, c2;
    for (lli i = 0; i < sz(v) - 1; i++) {
        r1 = v[i].first, c1 = v[i].second;
        r2 = v[i + 1].first, c2 = v[i + 1].second;

        if ((r1 + c1) % 2) {
            lli b = c1 + (r2 - r1);
            ans += (b - c2) / 2 + (b - c2) % 2;
        } else {
            if ((c2 - c1) == (r2 - r1)) {
                ans += r2 - r1;
            } else {
                lli b = c1 + (r2 - r1) - 1;
                ans += (b - c2) / 2 + (b - c2) % 2;
            }
        }
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