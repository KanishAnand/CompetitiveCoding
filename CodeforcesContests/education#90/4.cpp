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
    vector<lli> v;
    lli ans = 0;
    lli oans;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (i % 2 == 0) {
            ans += a;
        }
        v.pb(a);
    }

    oans = ans;

    vector<lli> dp(n + 2, 0);

    if (n > 1) {
        dp[1] = v[1] - v[0];
    }
    for (lli i = 3; i < n; i += 2) {
        lli val = v[i] - v[i - 1];
        lli val2 = val + dp[i - 2];
        if (val >= val2) {
            dp[i] = val;
        } else {
            dp[i] = val2;
        }
    }

    lli mx = 0;
    for (lli i = 0; i < n; i++) {
        mx = max(dp[i], mx);
    }

    ans = max(ans, oans + mx);

    //

    dp.clear();
    dp.resize(n + 2, 0);

    if (n > 2) {
        dp[2] = v[1] - v[2];
    }
    for (lli i = 4; i < n; i += 2) {
        lli val = v[i - 1] - v[i];
        lli val2 = val + dp[i - 2];
        if (val >= val2) {
            dp[i] = val;
        } else {
            dp[i] = val2;
        }
    }

    mx = 0;
    for (lli i = 0; i < n; i++) {
        mx = max(dp[i], mx);
    }
    ans = max(ans, oans + mx);

    cout << ans << endln;
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