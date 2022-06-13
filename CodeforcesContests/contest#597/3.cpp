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
    lli a;
    // vector<lli> v;
    string st;
    lli mod = 1e9 + 7;
    cin >> st;
    lli l = st.length();
    for (lli i = 0; i < l; i++) {
        if (st[i] == 'w' || st[i] == 'm') {
            cout << "0" << endl;
            rt;
        }
    }

    vector<lli> dp(l + 2, 0), dpf(l + 2, 1);
    // vector<lli> v;
    lli ans = 1;

    for (lli i = 1; i < l; i++) {
        if ((st[i] == st[i - 1]) && st[i] == 'u') {
            dpf[i] = (dp[i - 1] + dpf[i - 1]) % mod;
            dp[i] = dpf[i - 1];
            dp[i] %= mod;
            dpf[i] %= mod;
        } else if ((st[i] == st[i - 1]) && (st[i] == 'n')) {
            dpf[i] = (dp[i - 1] + dpf[i - 1]) % mod;
            dp[i] = dpf[i - 1];
            dp[i] %= mod;
            dpf[i] %= mod;
        }
        if ((i == l - 1) && (st[i] == 'u' || st[i] == 'n')) {
            ans *= (dp[i] + dpf[i]) % mod;
            ans %= mod;
        } else if ((st[i + 1] != st[i]) && (st[i] == 'u' || st[i] == 'n')) {
            ans *= (dp[i] + dpf[i]) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
    rt;
}
