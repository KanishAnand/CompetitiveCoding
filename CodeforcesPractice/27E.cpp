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

void solve() {
    lli n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
        return;
    }

    vector<lli> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    vector<vector<lli>> dp(n + 2, vector<lli>(10, 1e18 + 5));

    dp[1][0] = 1;

    for (lli i = 1; i <= 9; i++) {
        lli pw = 1;
        for (lli p = 1;; p++) {
            lli tmp = p + 1;
            if (pw > 1e18 / prime[i - 1]) {
                break;
            }
            pw *= prime[i - 1];
            for (lli no = 2; no <= n; no++) {
                if (no % tmp == 0) {
                    lli val = dp[no / tmp][i - 1];
                    if (val > 1e18 / pw) {
                        continue;
                    }
                    val *= pw;
                    dp[no][i] = min(dp[no][i], val);
                }
            }
        }
    }

    lli ans = 1e18 + 5;
    for (lli i = 1; i <= 9; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}