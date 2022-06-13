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
    lli n, a, m, k;
    cin >> n >> m >> k;
    vector<vector<lli>> arr(n + 2);

    string ss;
    for (lli i = 0; i < n; i++) {
        cin >> ss;
        for (lli j = 0; j < m; j++) {
            a = ss[j] - '0';
            arr[i].pb(a);
        }
    }

    vector<vector<vector<lli>>> dp(
        n + 2, vector<vector<lli>>(m + 2, vector<lli>(k + 5, -1)));

    lli no = k + 1;
    for (lli i = 0; i < m; i++) {
        lli val = arr[0][i];
        dp[0][i][val % no] = val;
    }

    for (lli i = 0; i < n - 1; i++) {
        for (lli j = 0; j < m; j++) {
            for (lli p = 0; p < no; p++) {
                if (dp[i][j][p] == -1) {
                    continue;
                }
                if (j != 0) {
                    lli val = dp[i][j][p] + arr[i + 1][j - 1];
                    dp[i + 1][j - 1][val % no] =
                        max(dp[i + 1][j - 1][val % no], val);
                }
                if (j != m - 1) {
                    lli val = dp[i][j][p] + arr[i + 1][j + 1];
                    dp[i + 1][j + 1][val % no] =
                        max(dp[i + 1][j + 1][val % no], val);
                }
            }
        }
    }

    lli ans = -1, ind = -1;
    for (lli i = 0; i < m; i++) {
        lli val = dp[n - 1][i][0];
        if (val > ans) {
            ans = val;
            ind = i;
        }
    }

    if (ans == -1) {
        cout << "-1" << endl;
        return;
    }

    cout << ans << endl;
    cout << ind + 1 << endl;

    lli val = ans, i = n - 1, mod = 0;

    string st = "";

    while (1) {
        if (i == 0) {
            break;
        }
        lli p = val - arr[i][ind];
        lli new_mod = p % no;
        if (ind != 0 && dp[i - 1][ind - 1][new_mod] == p) {
            st += 'L';
            mod = new_mod;
            val = p;
            ind--;
            i--;
        } else if (ind != m - 1 && dp[i - 1][ind + 1][new_mod] == p) {
            st += 'R';
            mod = new_mod;
            val = p;
            ind++;
            i--;
        }
    }

    cout << st << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}