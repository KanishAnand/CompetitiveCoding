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

double dp[101][101][101];

void solve() {
    lli r, s, p;
    cin >> r >> s >> p;
    dp[r][s][p] = 1;

    for (lli i = r; i >= 0; i--) {
        for (lli j = s; j >= 0; j--) {
            for (lli k = p; k >= 0; k--) {
                if (i > 0 && j > 0) {
                    double num = i * j;
                    double den = i * j + j * k + i * k;
                    double val = num / den;
                    dp[i][j - 1][k] += dp[i][j][k] * val;
                }
                if (j > 0 && k > 0) {
                    double num = j * k;
                    double den = i * j + j * k + i * k;
                    double val = num / den;
                    dp[i][j][k - 1] += dp[i][j][k] * val;
                }
                if (k > 0 && i > 0) {
                    double num = k * i;
                    double den = i * j + j * k + i * k;
                    double val = num / den;
                    dp[i - 1][j][k] += dp[i][j][k] * val;
                }
            }
        }
    }

    cout << fixed << setprecision(10);
    double ans = 0;
    for (lli i = 1; i <= r; i++) {
        ans += dp[i][0][0];
    }
    cout << ans << " ";
    ans = 0;
    for (lli i = 1; i <= s; i++) {
        ans += dp[0][i][0];
    }
    cout << ans << " ";
    ans = 0;
    for (lli i = 1; i <= p; i++) {
        ans += dp[0][0][i];
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