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
    lli n, a, l, r;
    cin >> n >> l >> r;
    lli no1 = 0, no2 = 0, no3 = 0;

    no1 = r / 3;
    no2 = r / 3;
    no3 = r / 3;
    if (r % 3 >= 1) {
        no2++;
    }
    if (r % 3 >= 2) {
        no3++;
    }

    no1 -= (l - 1) / 3;
    no2 -= (l - 1) / 3;
    no3 -= (l - 1) / 3;

    if ((l - 1) % 3 >= 1) {
        no2--;
    }
    if ((l - 1) % 3 >= 2) {
        no3--;
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(3, 0));
    dp[0][0] = no1;
    dp[0][1] = no2;
    dp[0][2] = no3;

    dp[0][0] %= MOD;
    dp[0][1] %= MOD;
    dp[0][2] %= MOD;

    for (lli i = 1; i < n; i++) {
        dp[i][0] =
            (((dp[i - 1][0] * no1) % MOD + (dp[i - 1][1] * no3) % MOD) % MOD +
             (dp[i - 1][2] * no2) % MOD) %
            MOD;
        dp[i][0] %= MOD;

        dp[i][1] =
            (((dp[i - 1][1] * no1) % MOD + (dp[i - 1][2] * no3) % MOD) % MOD +
             (dp[i - 1][0] * no2) % MOD) %
            MOD;
        dp[i][1] %= MOD;

        dp[i][2] =
            (((dp[i - 1][2] * no1) % MOD + (dp[i - 1][0] * no3) % MOD) % MOD +
             (dp[i - 1][1] * no2) % MOD) %
            MOD;
        dp[i][2] %= MOD;
    }

    cout << dp[n - 1][0] % MOD << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}