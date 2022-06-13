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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a;
    string st;
    cin >> st;
    n = len(st);

    lli last = -1;

    vector<lli> dp(n + 2, 0);
    dp[0] = 1;
    if (st[0] != '?') {
        last = 0;
    }

    for (lli i = 1; i < n; i++) {
        lli gp = i - last - 1;

        if (st[i] != '?') {
            if (last != -1) {
                if (st[last] == st[i]) {
                    if (gp % 2 == 1) {
                        dp[i] = dp[i - 1] + 1;
                    } else {
                        dp[i] = gp + 1;
                    }
                } else {
                    if (gp % 2 == 0) {
                        dp[i] = dp[i - 1] + 1;
                    } else {
                        dp[i] = gp + 1;
                    }
                }
            } else {
                dp[i] = dp[i - 1] + 1;
            }
            last = i;
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        ans += dp[i];
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