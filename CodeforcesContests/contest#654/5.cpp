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
    lli n, a, p;
    cin >> n >> p;
    vector<lli> v;
    lli mx = -1;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mx = max(mx, a);
        v.pb(a);
    }

    sort(all(v));

    vector<lli> ans;
    for (lli x = 1; x < mx; x++) {
        lli no = x;
        lli flag = 1;
        for (lli i = 0; i < n; i++) {
            auto it = upper_bound(v.begin(), v.end(), no);
            lli calc = it - v.begin();
            lli ch = calc - i;
            if (ch <= 0) {
                flag = 0;
                break;
            }
            if (ch % p == 0) {
                flag = 0;
                break;
            }
            no++;
        }
        if (flag == 1) {
            ans.pb(x);
        }
    }

    cout << sz(ans) << endln;
    for (lli i = 0; i < sz(ans); i++) {
        cout << ans[i] << " ";
    }
    cout << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}