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

lli INF = -1e8;

void solve() {
    lli n, m, k, a;
    cin >> n >> m >> k;

    vector<vector<lli>> mat(n + 2);
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> a;
            mat[i].pb(a);
        }
    }

    lli MAX_LEN = m / 2;
    vector<vector<lli>> store(n + 2, vector<lli>(k + 2, INF));

    for (lli i = 0; i < n; i++) {
        vector<vector<lli>> prevdp(m + 2, vector<lli>(k + 2, INF));
        prevdp[0][0] = 0;

        for (lli j = 0; j < m; j++) {
            vector<vector<lli>> dp(m + 2, vector<lli>(k + 2, INF));

            for (lli len = 0; len <= MAX_LEN; len++) {
                for (lli rem = 0; rem < k; rem++) {
                    dp[len][rem] = max(dp[len][rem], prevdp[len][rem]);
                    if (len != MAX_LEN) {
                        dp[len + 1][(rem + mat[i][j]) % k] = max(dp[len + 1][(rem + mat[i][j]) % k],
                                                                 prevdp[len][rem] + mat[i][j]);
                    }
                }
            }
            prevdp = dp;
        }

        for (lli rem = 0; rem < k; rem++) {
            for (lli len = 0; len <= MAX_LEN; len++) {
                store[i][rem] = max(store[i][rem], prevdp[len][rem]);
            }
        }
    }

    for (lli i = 1; i < n; i++) {
        vector<lli> tmpStore(k + 2, INF);
        for (lli rem = 0; rem < k; rem++) {
            for (lli prevRem = 0; prevRem < k; prevRem++) {
                tmpStore[(rem + prevRem) % k] = max(tmpStore[(rem + prevRem) % k], store[i - 1][prevRem] + store[i][rem]);
            }
        }
        for (lli rem = 0; rem < k; rem++) {
            store[i][rem] = tmpStore[rem];
        }
    }

    cout << store[n - 1][0] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}