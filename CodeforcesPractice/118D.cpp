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
    lli n1, n2, k1, k2, a;
    lli mod = 1e8;
    vector<lli> v;
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<lli>>> dp(
        n1 + n2 + 2, vector<vector<lli>>(max(n1, n2) + 2, vector<lli>(2, 0)));
    dp[0][1][0] = 1;
    dp[0][1][1] = 1;

    for (lli i = 1; i < k1; i++) {
        if (i + 1 <= n1) {
            dp[i][i + 1][0] += dp[0][1][0];
            dp[i][i + 1][0] %= mod;
        }
    }
    // cout << "kan" << endl;
    for (lli i = 1; i < k2; i++) {
        if (i + 1 <= n2) {
            dp[i][i + 1][1] += dp[0][1][1];
            dp[i][i + 1][1] %= mod;
        }
    }
    // cout << "kan" << endl;

    for (lli i = 1; i < n1 + n2; i++) {
        // cout << "kan5" << endl;
        for (lli j = 1; j <= n1; j++) {
            if (i + 1 - j >= 1 && i + 1 - j <= n2) {
                dp[i][j][0] += dp[i - 1][i + 1 - j][1];
                dp[i][j][0] %= mod;
            }
        }

        // cout << "kan6" << endl;
        for (lli j = 1; j <= n2; j++) {
            if (i + 1 - j >= 1 && i + 1 - j <= n1) {
                dp[i][j][1] += dp[i - 1][i + 1 - j][0];
                dp[i][j][1] %= mod;
            }
        }
        // cout << "kan1"
        //  << " " << i << endl;

        for (lli j = i + 1; j < i + k1; j++) {
            for (lli k = 1; k <= n1; k++) {
                if (k + j - i <= n1 && i + 1 - k >= 1 && i + 1 - k <= n2) {
                    // dp[j][k + j - i][0] += dp[i][k][0];
                    dp[j][k + j - i][0] += dp[i - 1][i + 1 - k][1];

                    dp[j][k + j - i][0] %= mod;
                }
            }
        }
        // cout << "kan3" << endl;

        for (lli j = i + 1; j < i + k2; j++) {
            for (lli k = 1; k <= n2; k++) {
                if (k + j - i <= n2 && i + 1 - k >= 1 && i + 1 - k <= n1) {
                    // dp[j][k + j - i][1] += dp[i][k][1];
                    dp[j][k + j - i][1] += dp[i - 1][i + 1 - k][0];
                    dp[j][k + j - i][1] %= mod;
                }
            }
        }
        // cout << "kan2" << endl;
    }

    lli ans = 0;
    // for (lli i = 1; i <= n1; i++) {
    ans += dp[n1 + n2 - 1][n1][0];
    ans %= mod;
    // }
    // cout << ans << endl;
    // for (lli i = 1; i <= n2; i++) {
    ans += dp[n1 + n2 - 1][n2][1];
    ans %= mod;
    // }

    cout << ans << endl;
    rt;
}
