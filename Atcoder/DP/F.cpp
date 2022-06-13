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
    string s, t, ans;
    cin >> s >> t;
    lli n = s.length(), m = t.length();
    vector<lli> ve(m + 2, 0);
    vector<vector<lli>> dp(n + 2, ve);

    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] =
                    max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + 1});
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    lli a = n, b = m;
    while (a > 0 && b > 0) {
        if (dp[a][b] == dp[a - 1][b]) {
            a--;
        } else if (dp[a][b] == dp[a][b - 1]) {
            b--;
        } else {
            a--;
            b--;
            ans.pb(s[a]);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    rt;
}
