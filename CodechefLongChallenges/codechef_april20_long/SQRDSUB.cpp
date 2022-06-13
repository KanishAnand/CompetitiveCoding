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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(abs(a));
    }
    vector<lli> pref(n + 2, -1), suff(n + 2, -1);

    lli prev = 0;

    for (lli i = 0; i < n; i++) {
        if (v[i] % 2 == 1) {
            prev++;
        } else {
            if (v[i] % 4 != 0) {
                pref[i] = prev;
            }
            prev = 0;
        }
    }

    prev = 0;

    for (lli i = n - 1; i >= 0; i--) {
        if (v[i] % 2 == 1) {
            prev++;
        } else {
            if (v[i] % 4 != 0) {
                suff[i] = prev;
            }
            prev = 0;
        }
    }

    lli sub = 0;
    for (lli i = 0; i < n; i++) {
        if (v[i] % 2 == 0 && v[i] % 4 != 0) {
            sub += (pref[i] + 1) * (suff[i] + 1);
        }
    }
    lli ans = (n * (n + 1)) / 2 - sub;
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