#include <bits/stdc++.h>
using namespace std;
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

lli n, inf = -1;
vector<vector<lli>> store(10);

lli check(lli a) {
    lli pp = (1ll << 8);
    vector<vector<lli>> dp(n + 5, vector<lli>(pp + 3, -1));

    for (lli i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (lli i = 0; i < n; i++) {
        for (lli mask = 0; mask < pp; mask++) {
            for (lli j = 1; j <= 8; j++) {
                lli jj = j - 1;
                lli ch = (1ll << jj);

                if ((mask & ch) != 0) {
                    continue;
                }

                auto it = lower_bound(store[j].begin(), store[j].end(), i);
                lli len = store[j].end() - it;

                lli new_mask = (mask | ch);

                if (len >= a) {
                    if (a == 0) {
                        dp[i][new_mask] = max(dp[i][new_mask], dp[i][mask]);
                    } else {
                        lli start_ind = it - store[j].begin();
                        lli ind = start_ind + a - 1;
                        ind = store[j][ind];
                        ind++;
                        dp[ind][new_mask] = max(dp[ind][new_mask], dp[i][mask]);
                    }
                }
                if (a + 1 <= len) {
                    lli start_ind = it - store[j].begin();
                    lli ind = start_ind + a;
                    ind = store[j][ind];
                    ind++;
                    if (dp[i][mask] != inf) {
                        dp[ind][new_mask] =
                            max(dp[ind][new_mask], dp[i][mask] + 1ll);
                    }
                }
            }
        }
    }

    lli val = -1;
    lli final_mask = pp - 1;
    for (lli i = 0; i <= n; i++) {
        val = max(val, dp[i][final_mask]);
    }
    return val;
}

void solve() {
    lli a;
    cin >> n;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        store[a].pb(i);
    }

    lli beg = 0, end = n, ans = 1;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli p = check(mid);
        if (p != inf) {
            beg = mid + 1;
            lli val = p * (mid + 1) + (8 - p) * mid;
            ans = max(ans, val);
        } else {
            end = mid - 1;
        }
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