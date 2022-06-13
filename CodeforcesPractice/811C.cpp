#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> right(5004, -1), left(5004, -1);
    vector<vector<lli>> bol(n + 2, vector<lli>(n + 2, 0));
    vector<lli> dp(n + 2, 0);

    for (lli i = n - 1; i >= 0; i--) {
        lli val = v[i];
        if (right[val] == -1) {
            right[val] = i;
        }
    }

    for (lli i = 0; i < n; i++) {
        lli val = v[i];
        if (left[val] == -1) {
            left[val] = i;
        }
    }

    for (lli i = 0; i < n; i++) {
        lli mn = n + 2, mx = -1;
        for (lli j = i; j < n; j++) {
            mn = min(mn, left[v[j]]);
            mx = max(mx, right[v[j]]);
            if (mn >= i && mx <= j) {
                bol[i][j] = 1;
            }
        }
    }

    if (bol[0][0] == 1) {
        dp[0] = v[0];
    }

    for (lli i = 1; i < n; i++) {
        lli val = 0;
        vector<lli> cnt(5002, 0);

        for (lli j = i; j >= 0; j--) {
            if (cnt[v[j]] == 0) {
                val ^= v[j];
            }
            cnt[v[j]]++;

            if (bol[j][i] == 1) {
                if (j != 0) {
                    dp[i] = dp[j - 1] + val;
                } else {
                    dp[i] = val;
                }
                break;
            }
        }

        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}