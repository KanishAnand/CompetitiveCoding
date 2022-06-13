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

vector<lli> v;

void solve() {
    lli sum, n;
    cin >> sum >> n;

    vector<lli> ans;
    while (sum > 0) {
        lli el = max(n - 1 - sz(ans), 0ll);
        lli val = sum - el;
        // if (val == 1) {
        //     break;
        // }

        auto it = upper_bound(v.begin(), v.end(), val);
        it--;
        lli no = *it;
        // cout << val << " " << no << endl;
        ans.pb(no);
        sum -= no;
    }

    // for (lli i = 1; i <= sum; i++) {
    //     ans.pb(1);
    // }

    // reverse(ans.begin(), ans.end());
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

    lli p = 1, cnt = 0;
    while (cnt <= 8) {
        for (lli j = 1; j <= 9; j++) {
            v.pb(p * j);
        }
        p *= 10;
        cnt++;
    }
    v.pb(1e9);
    // cout << sz(v) << endl;

    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}