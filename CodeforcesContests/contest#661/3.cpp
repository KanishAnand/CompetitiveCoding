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
    vector<lli> mp(100, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        v.pb(a);
    }

    sort(all(v));
    lli ans = 0;

    for (lli i = 0; i < n; i++) {
        for (lli j = i + 1; j < n; j++) {
            vector<lli> cmp = mp;
            lli sum = v[i] + v[j];
            cmp[v[i]]--;
            cmp[v[j]]--;
            lli val = 1;
            for (lli ii = 0; ii < n; ii++) {
                lli p = v[ii];
                lli q = sum - p;
                if (q < 0) {
                    continue;
                }
                if (p != q && (cmp[p] != 0 && cmp[q] != 0)) {
                    cmp[p]--;
                    cmp[q]--;
                    val++;
                }
                if (p == q && cmp[p] >= 2) {
                    cmp[p] -= 2;
                    val++;
                }
            }
            ans = max(ans, val);
        }
    }
    cout << ans << endln;
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