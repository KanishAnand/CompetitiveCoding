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
    lli n, a, b;
    cin >> n;
    vector<pair<pair<lli, lli>, lli>> v;
    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({{a, b}, i});
    }

    sort(all(v));

    lli ind = -1, mx = v[0].first.second;
    for (lli i = 1; i < n; i++) {
        if (v[i].first.first > mx) {
            ind = i;
            break;
        }
        mx = max(mx, v[i].first.second);
    }

    if (ind == -1) {
        cout << "-1" << endl;
    } else {
        vector<lli> ans(n + 2, 0);
        for (lli i = 0; i < ind; i++) {
            lli p = v[i].second;
            ans[p] = 1;
        }
        for (lli i = ind; i < n; i++) {
            lli p = v[i].second;
            ans[p] = 2;
        }
        for (lli i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
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