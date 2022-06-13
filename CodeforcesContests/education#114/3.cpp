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
    lli n, m, a, sum = 0;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        v.pb(a);
    }
    sort(all(v));

    cin >> m;
    lli x, y;
    for (lli ch = 0; ch < m; ch++) {
        cin >> x >> y;
        auto it = lower_bound(v.begin(), v.end(), x);
        lli cost1, cost2, ans;

        if (it == v.end()) {
            it--;
        }
        lli ind = it - v.begin();

        cost1 = max(0ll, x - v[ind]);
        cost1 += max(0ll, y - (sum - v[ind]));
        ans = cost1;

        if (ind != 0) {
            ind--;
            cost2 = max(0ll, x - v[ind]);
            cost2 += max(0ll, y - (sum - v[ind]));
            ans = min(ans, cost2);
        }

        cout << ans << endln;
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