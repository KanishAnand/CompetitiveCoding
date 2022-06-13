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
    lli n, a, m, x, y;
    vector<string> v;
    string st;
    cin >> n >> m >> x >> y;
    fr(i, 0, n) {
        cin >> st;
        v.pb(st);
    }

    vector<vector<lli>> cnt(m + 1, {0, 0});
    fr(i, 0, m) {
        fr(j, 0, n) {
            if (v[j][i] == '.') {
                cnt[i][0]++;
            } else {
                cnt[i][1]++;
            }
        }
    }

    vector<lli> pref(m + 1, 0), pref2(m + 1, 0);
    pref[0] = cnt[0][0];
    pref2[0] = cnt[0][1];
    fr(i, 1, m) {
        pref[i] = pref[i - 1] + cnt[i][0];
        pref2[i] = pref2[i - 1] + cnt[i][1];
    }

    vector<vector<lli>> dp(m + 2, {-1, -1});

    for (lli i = x - 1; i <= y - 1 && i < m; i++) {
        dp[i][0] = pref2[i] - pref2[0] + cnt[0][1];
        dp[i][1] = pref[i] - pref[0] + cnt[0][0];
    }

    for (lli i = x; i < m; i++) {
        if (i + x - 1 < m) {
            for (lli j = i + x - 1; j <= i + y - 1 && j < m; j++) {
                if (dp[i - 1][1] != -1) {
                    if (dp[j][0] == -1) {
                        dp[j][0] =
                            pref2[j] - pref2[i] + cnt[i][1] + dp[i - 1][1];
                    } else {
                        dp[j][0] = min(dp[j][0], pref2[j] - pref2[i] +
                                                     cnt[i][1] + dp[i - 1][1]);
                    }
                    if (dp[j][1] == -1) {
                        dp[j][1] = pref[j] - pref[i] + cnt[i][0] + dp[i - 1][0];
                    } else {
                        dp[j][1] = min(dp[j][1], pref[j] - pref[i] + cnt[i][0] +
                                                     dp[i - 1][0]);
                    }
                }
            }
        } else {
            break;
        }
    }
    // fr(i, 0, m) {
    // cout << dp[i][0] << " " << dp[i][1] << endl;
    // }

    cout << min(dp[m - 1][0], dp[m - 1][1]) << endl;
    rt;
}