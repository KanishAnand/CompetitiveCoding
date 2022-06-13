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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a;
    cin >> n;
    vector<pair<double, double>> v;

    lli t;
    double l, r;
    for (lli i = 0; i < n; i++) {
        cin >> t >> l >> r;
        if (t == 2) {
            r -= 0.1;
        } else if (t == 3) {
            l += 0.1;
        } else if (t == 4) {
            l += 0.1;
            r -= 0.1;
        }

        if (l <= r) {
            v.pb({l, r});
        }
    }

    sort(all(v));
    n = sz(v);

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        for (lli j = i + 1; j < n; j++) {
            if (v[i].second >= v[j].first) {
                ans++;
            }
        }
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