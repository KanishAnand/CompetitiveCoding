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
    lli n, a, k;
    cin >> n >> k;
    vector<lli> v, dp;
    dp.resize(n + 5, -1);
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }
    dp[0] = 0;

    fr(i, 0, n) {
        for (lli j = i + 1; j <= i + k && j < n; j++) {
            lli val = abs(v[j] - v[i]);
            if (dp[j] == -1) {
                dp[j] = dp[i] + val;
            } else {
                dp[j] = min(dp[j], dp[i] + val);
            }
        }
        // fr(p, 0, n) {
        //     cout << dp[p] << " ";
        // }
        // cout << endl;
    }

    // fr(i, 0, n) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n - 1] << endl;
    rt;
}
