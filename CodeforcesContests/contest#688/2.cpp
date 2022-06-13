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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

lli fun(lli val, vector<lli> &v) {
    lli n = sz(v);
    vector<vector<lli>> dp(n + 2, vector<lli>(2, 0));
    vector<vector<lli>> sum(n + 2, vector<lli>(2, 0));

    dp[0][0] = abs(v[0] - val);
    sum[0][0] = val - v[0];

    dp[0][1] = 0;
    sum[0][1] = 0;

    for (lli i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + abs(sum[i - 1][0] + v[i] - val);
        sum[i][0] = sum[i - 1][0] + val - (sum[i - 1][0] + v[i]);

        lli p = dp[i - 1][1] + abs(sum[i - 1][1] + v[i] - val);
        lli q = dp[i - 1][0];

        if (p < q) {
            dp[i][1] = p;
            sum[i][1] = sum[i - 1][1] + val - (sum[i - 1][1] + v[i]);
        } else {
            dp[i][1] = q;
            sum[i][1] = sum[i - 1][0];
        }
    }

    lli ans = min(dp[n - 1][0], dp[n - 1][1]);
    return ans;
}

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    lli start = 5 * 1e8, end = -5 * 1e8;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        start = min(start, a);
        end = max(end, a);
    }

    lli ans = 1e17;

    while ((end - start) >= 2) {
        // cout << start << " " << end << endl;
        lli mid = (start + end) / 2;
        lli val1 = fun(mid - 1, v);
        lli val2 = fun(mid, v);
        lli val3 = fun(mid + 1, v);
        ans = min({ans, val1, val2, val3});
        // cout << val1 << " " << val2 << " " << val3 << endl;
        if (val1 >= val2 && val2 >= val3) {
            start = mid;
        } else if (val1 <= val2 && val2 <= val3) {
            end = mid;
        } else if (val1 >= val2 && val3 >= val2) {
            ans = val2;
            start = end + 3;
            // cout << mid << endl;
            break;
        } else {
            break;
        }
    }

    // cout << start << " " << end << endl;
    for (lli i = start; i <= end; i++) {
        ans = min(ans, fun(i, v));
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