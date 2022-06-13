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
    lli n, a, k;
    cin >> n >> k;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> pref(n + 2);
    pref[0] = v[0];
    for (lli i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + v[i];
    }

    lli mask = 0;
    for (lli bit = 55; bit >= 0; bit--) {
        lli tmp = (1ll << bit);
        tmp = (tmp | mask);
        vector<vector<bool>> dp(n + 2, vector<bool>(k + 2, 0));

        for (lli i = 0; i < n; i++) {
            lli val = (pref[i] & tmp);
            if (val == tmp) {
                dp[i][1] = 1;
            }
        }

        for (lli i = 2; i <= k; i++) {
            for (lli j = 0; j < n; j++) {
                for (lli p = 0; p < j; p++) {
                    if (dp[p][i - 1] == 1) {
                        lli val = pref[j] - pref[p];
                        lli pp = (val & tmp);
                        if (pp == tmp) {
                            dp[j][i] = 1;
                            break;
                        }
                    }
                }
            }
        }

        if (dp[n - 1][k] == 1) {
            mask = tmp;
        }
    }

    cout << mask << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}