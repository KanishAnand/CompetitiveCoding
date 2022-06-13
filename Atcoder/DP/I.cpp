#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n;
    float a;
    vector<float> v;
    cin >> n;
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }

    vector<vector<double>> dp(n + 2, vector<double>(n + 2, 0));
    // dp[i][j]  = till ith coin j number of heads
    dp[0][0] = 1 - v[0];
    dp[0][1] = v[0];
    for (lli i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - v[i]);
        for (lli j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - v[i]) + dp[i - 1][j - 1] * v[i];
        }
    }

    double ans = 0;
    for (lli j = n / 2 + 1; j <= n; j++) {
        ans += dp[n - 1][j];
    }

    cout << fixed << setprecision(10) << ans << endl;
    // cout << ans << endl;
    rt;
}
