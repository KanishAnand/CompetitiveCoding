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
    lli sum, n;
    cin >> sum >> n;
    vector<lli> ans;

    lli p = 1;
    while (sum > 0) {
        lli dig = sum % 10;
        for (lli i = 0; i < dig; i++) {
            ans.pb(p);
        }
        sum /= 10;
        p *= 10;
    }

    while (sz(ans) < n) {
        lli ind = -1;
        for (lli i = 0; i < sz(ans); i++) {
            if (ans[i] != 1) {
                ind = i;
                break;
            }
        }
        lli val = ans[ind] / 10;
        ans[ind] = val;
        for (lli i = 0; i < 9; i++) {
            ans.pb(val);
        }
        sort(all(ans));
    }

    for (lli i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    lli final = 0;
    for (lli i = n - 1; i < sz(ans); i++) {
        final += ans[i];
    }
    cout << final << endl;
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