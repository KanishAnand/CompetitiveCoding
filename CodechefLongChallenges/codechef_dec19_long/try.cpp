#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
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
    lli n, a;
    n = 18;
    vector<vector<lli>> dp(18, vector<lli>(9, 0));
    fr(i, 0, 10) {
        dp[0][i] = 1;
    }

    for (lli i = 1; i < 18; i++) {
        for (lli j = 0; j < 10; j++) {
            lli val = 0;
            for (lli k = 0; k <= j; k++) {
                val += dp[i - 1][k];
            }
            dp[i][j] = val;
        }
    }
    lli ans = 0;
    for (lli i = 0; i < 10; i++) {
        cout << dp[17][i] << endl;
        ans += dp[17][i];
    }
    cout << endl;
    cout << ans << endl;
    rt;
}
