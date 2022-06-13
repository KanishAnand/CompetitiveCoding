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
    string st;
    vector<string> s, p;
    input(n, v);
    fr(i, 0, n) {
        cin >> st;
        s.pb(st);
        reverse(st.begin(), st.end());
        p.pb(st);
    }

    vector<vector<lli>> dp(n + 2, vector<lli>(2, -1));
    dp[0][0] = 0;
    dp[0][1] = v[0];

    fr(i, 1, n) {
        if (s[i] >= s[i - 1] && dp[i - 1][0] != -1) {
            dp[i][0] = dp[i - 1][0];
        }
        if (s[i] >= p[i - 1] && dp[i - 1][1] != -1) {
            if (dp[i][0] == -1) {
                dp[i][0] = dp[i - 1][1];
            } else {
                dp[i][0] = min(dp[i - 1][1], dp[i][0]);
            }
        }

        if (p[i] >= s[i - 1] && dp[i - 1][0] != -1) {
            dp[i][1] = dp[i - 1][0] + v[i];
        }
        if (p[i] >= p[i - 1] && dp[i - 1][1] != -1) {
            if (dp[i][1] == -1) {
                dp[i][1] = dp[i - 1][1] + v[i];
            } else {
                dp[i][1] = min(dp[i - 1][1] + v[i], dp[i][1]);
            }
        }
    }

    if (dp[n - 1][0] == -1 && dp[n - 1][1] == -1) {
        cout << "-1" << endl;
    } else if (dp[n - 1][0] == -1 || dp[n - 1][1] == -1) {
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    } else {
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }

    rt;
}
