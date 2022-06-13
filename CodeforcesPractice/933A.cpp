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

    vector<lli> pref(n + 2, 1), suff(n + 2, 1);
    vector<lli> pref2(n + 2, 1), suff2(n + 2, 1);
    lli ans = 1;

    for (lli i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            pref[i] = pref[i - 1] + 1;
            ans = max(ans, pref[i]);
        }
        if (v[i] <= v[i - 1]) {
            pref2[i] = pref2[i - 1] + 1;
            ans = max(ans, pref[i]);
        }
    }

    for (lli i = n - 2; i >= 0; i--) {
        if (v[i] <= v[i + 1]) {
            suff[i] = suff[i + 1] + 1;
            ans = max(ans, suff[i]);
        }
        if (v[i] >= v[i + 1]) {
            suff2[i] = suff2[i + 1] + 1;
            ans = max(ans, suff2[i]);
        }
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (lli len = 2; len <= n; len++) {
        for (lli i = 0; i < n - len + 1; i++) {
            if (v[i] >= v[i + 1] && dp[i + 1][i + len - 1] == 1) {
                dp[i][i + len - 1] = 1;
            }
            if (dp[i][i + len - 1] == 1) {
                lli val = len;
                if (i + len < n && v[i] <= v[i + len]) {
                    val += suff[i + len];
                }
                if (i - 1 >= 0 && v[i + len - 1] >= v[i - 1]) {
                    val += pref[i - 1];
                }
                ans = max(ans, val);
            } else {
                if (i - 1 >= 0 && v[i - 1] <= v[i + len - 1]) {
                    lli val = pref[i - 1] + pref2[i + len - 1];
                    ans = max(ans, val);
                }
                if (i + len < n && v[i] <= v[i + len]) {
                    lli val = suff[i + len] + suff2[i];
                    ans = max(ans, val);
                }
            }
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