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
    lli n, a, x;
    cin >> n >> x;
    vector<lli> v;
    lli mx = -1;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mx = max(a, mx);
        v.pb(a);
    }

    lli ans = 0, tmpx = x;
    while (tmpx > 0 && mx > 0) {
        ans += mx;
        tmpx--;
        mx--;
    }

    for (lli i = 0; i < n; i++) {
        v.pb(v[i]);
    }

    vector<lli> pref, preff;
    pref.pb(v[0]);
    preff.pb((v[0] * (v[0] + 1)) / 2);

    for (lli i = 1; i < sz(v); i++) {
        pref.pb(pref[i - 1] + v[i]);
        preff.pb(preff[i - 1] + (v[i] * (v[i] + 1)) / 2);
    }

    for (lli i = n; i < sz(v); i++) {
        if (v[i] > x) {
            continue;
        }
        lli val = pref[i] - x;
        lli tmp = x;
        auto it = lower_bound(pref.begin(), pref.end(), val);
        lli ind = it - pref.begin();
        lli no = preff[i] - preff[ind];
        tmp -= (pref[i] - pref[ind]);
        lli p = v[ind];
        lli q = p - tmp;
        no += ((p * (p + 1)) / 2) - ((q * (q + 1)) / 2);
        ans = max(ans, no);
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