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
    lli n, a;
    cin >> n;
    vector<lli> v, dp;
    dp.resize(n + 5, -1);
    fr(i, 0, n) {
        cin >> a;
        v.pb(a);
    }
    dp[0] = 0;

    fr(i, 0, n) {
        lli val1 = 0, val2 = 0;
        if (i + 1 < n) {
            val1 = abs(v[i + 1] - v[i]);
        }
        if (i + 2 < n) {
            val2 = abs(v[i + 2] - v[i]);
        }
        if (dp[i + 1] != -1) {
            dp[i + 1] = min(dp[i + 1], val1 + dp[i]);
        } else {
            dp[i + 1] = val1 + dp[i];
        }
        if (dp[i + 2] != -1) {
            dp[i + 2] = min(dp[i + 2], val2 + dp[i]);
        } else {
            dp[i + 2] = val2 + dp[i];
        }
    }

    // fr(i, 0, n) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n - 1] << endl;
    rt;
}
