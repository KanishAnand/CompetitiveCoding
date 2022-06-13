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
    v.pb(0);

    vector<lli> pref(n + 2, 0), suff(n + 2, 0);

    pref[0] = v[0];
    for (lli i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + v[i];
    }
    pref[n] = pref[n - 1];
    suff[n - 1] = v[n - 1];
    for (lli i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + v[i];
    }

    vector<vector<lli>> dp(5, vector<lli>(n + 2, 0));
    vector<vector<lli>> ind(5, vector<lli>(n + 2, 0));

    for (lli i = 1; i <= n; i++) {
        dp[1][i] = pref[i - 1];
        ind[1][i] = i;
    }

    for (lli i = 2; i <= 3; i++) {
        for (lli j = 0; j <= n; j++) {
            lli val = -1e16;
            for (lli k = 0; k <= j; k++) {
                lli p = dp[i - 1][k];
                lli q = pref[j] - pref[k] - v[j] + v[k];
                if (i == 2) {
                    q = -q;
                }
                p += q;
                if (i == 3) {
                    p -= suff[j];
                }
                if (p > val) {
                    val = p;
                    ind[i][j] = k;
                }
            }
            dp[i][j] = val;
        }
    }

    lli mx = -1e16;
    lli ans[4];

    for (lli i = 0; i <= n; i++) {
        if (dp[3][i] > mx) {
            mx = dp[3][i];
            ans[3] = i;
            ans[2] = ind[3][i];
            ans[1] = ind[2][ans[2]];
        }
    }

    cout << ans[1] << " " << ans[2] << " " << ans[3] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}