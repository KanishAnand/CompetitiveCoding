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
    lli n, a, wt, b;
    vector<lli> v, w;
    cin >> n >> wt;
    vector<vector<lli>> dp(n + 1, vector<lli>(100002, 1e13));
    fr(i, 0, n) {
        cin >> a >> b;
        w.pb(a);
        v.pb(b);
    }

    fr(i, 0, n) {
        dp[i][0] = 0;
    }

    dp[0][v[0]] = w[0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= 100000; j++) {
            if (j >= v[i]) {
                dp[i][j] = min(dp[i - 1][j - v[i]] + w[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (lli i = 100000; i >= 0; i--) {
        if (dp[n - 1][i] <= wt) {
            cout << i << endl;
            rt;
        }
    }

    rt;
}