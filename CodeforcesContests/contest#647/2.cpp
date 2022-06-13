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
    vector<lli> mp(2000, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        mp[a] = 1;
    }

    if (n % 2 == 1) {
        cout << "-1" << endl;
        return;
    }

    lli no = v[0];
    lli ans = -1;

    for (lli i = 1; i < n; i++) {
        lli val = no ^ v[i], flag = 0;
        for (lli j = 0; j < n; j++) {
            lli p = v[j] ^ val;
            if (mp[p] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            if (ans == -1) {
                ans = val;
            } else {
                ans = min(ans, val);
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