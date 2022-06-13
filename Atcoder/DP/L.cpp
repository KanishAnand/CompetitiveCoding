#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    vector<lli> v;
    cin >> n;
    vector<lli> pref(n + 1, 0);
    input(n, v);
    // lli dp[n + 1][n + 1][2];
    // vector<vector<vector<lli>>> dp(n + 1,
    //                                vector<lli>(n + 1, vector<lli>(2, 0)));
    vector<vector<vector<lli>>> dp(
        n + 1, vector<vector<lli>>(n + 1, vector<lli>{0, 0}));
    fr(i, 0, n) {
        dp[i][i][0] = v[i];
        dp[i][i][1] = v[i];
    }

    pref[0] = v[0];
    fr(i, 1, n) {
        pref[i] = pref[i - 1] + v[i];
    }

    for (lli i = 2; i <= n; i++) {
        for (lli j = 0; j <= n - i; j++) {
            lli l = j, r = j + i - 1;
            dp[l][r][0] =
                max(v[l] + pref[r] - pref[l] - dp[l + 1][r][1],
                    v[r] + pref[r - 1] - pref[l] + v[l] - dp[l][r - 1][1]);
            dp[l][r][1] =
                max(v[l] + pref[r] - pref[l] - dp[l + 1][r][0],
                    v[r] + pref[r - 1] - pref[l] + v[l] - dp[l][r - 1][0]);
        }
    }

    cout << 2 * dp[0][n - 1][0] - pref[n - 1] << endl;
    rt;
}