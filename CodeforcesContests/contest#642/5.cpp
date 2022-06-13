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
    lli n, a, k;
    cin >> n >> k;
    string st;
    cin >> st;

    vector<lli> dp(n + 2, 0), pref(n + 2, 0);
    if (st[0] == '1') {
        pref[0] = 1;
    }

    for (lli i = 1; i < n; i++) {
        pref[i] = pref[i - 1];
        if (st[i] == '1') {
            pref[i]++;
        }
    }

    for (lli i = 0; i < n; i++) {
        lli val = i - k;

        if (val >= 0) {
            dp[i] = min(pref[i - 1], dp[i - k] + pref[i - 1] - pref[i - k]);
        } else {
            if (i > 0) {
                dp[i] = pref[i - 1];
            }
        }
        if (st[i] == '0') {
            dp[i]++;
        }
    }

    lli ans = pref[n - 1];
    for (lli i = 0; i < n; i++) {
        lli val = dp[i] + pref[n - 1] - pref[i];
        ans = min(ans, val);
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