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
    lli n, a, m, b;
    cin >> n >> m;
    vector<pair<lli, lli>> v;
    vector<lli> store;

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        v.pb({a, b});
        store.pb(a);
    }

    sort(all(store));

    vector<lli> pref(m + 2, 0);
    pref[0] = store[0];

    for (lli i = 1; i < m; i++) {
        pref[i] = pref[i - 1] + store[i];
    }

    lli ans = 0;

    if (m >= n) {
        lli p = m - n;
        ans = pref[m - 1] - pref[p] + store[p];
    }

    for (lli i = 0; i < m; i++) {
        lli tmp = n;
        a = v[i].first;
        b = v[i].second;

        auto it = upper_bound(store.begin(), store.end(), b);
        if (it == store.end()) {
            lli val = a;
            tmp--;
            val += tmp * b;
            ans = max(ans, val);
            continue;
        }

        lli ind = it - store.begin();
        lli no = store.end() - it;
        if (no >= n) {
            continue;
        }

        lli val = pref[m - 1] - pref[ind] + store[ind];
        if (a >= store[ind]) {
            tmp -= no;
            val += tmp * b;
        } else {
            tmp -= no;
            val += a;
            tmp--;
            val += tmp * b;
        }

        if (val > ans) {
            ans = val;
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