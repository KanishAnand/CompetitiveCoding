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
    vector<vector<lli>> men;
    men.resize(n + 2);
    lli mod = 1e9 + 7;

    fr(i, 0, n) {
        fr(j, 0, n) {
            cin >> a;
            if (a == 1) {
                men[j].pb(i);
            }
        }
    }

    vector<vector<lli>> dp(1 << n, vector<lli>(n + 2, 0));

    fr(i, 0, men[0].size()) {
        a = men[0][i];
        dp[1 << a][0] = 1;
    }

    for (lli mask = 1; mask < (1 << n); mask++) {
        lli c = -1;
        lli temp = mask;
        while (temp > 0) {
            if (temp % 2 == 1) {
                c++;
            }
            temp /= 2;
        }
        if (c == 0) {
            continue;
        }
        for (lli j = 0; j < men[c].size(); j++) {
            a = men[c][j];
            if ((mask & (1 << a)) != 0) {
                lli p = 1 << n;
                --p;
                p = p ^ (1 << a);
                dp[mask][c] += dp[mask & ~(1 << a)][c - 1];
                dp[mask][c] %= mod;
            }
        }
    }

    lli ans = 0;
    for (lli mask = 1; mask < (1 << n); mask++) {
        ans += dp[mask][n - 1];
        ans %= mod;
    }

    cout << ans << endl;
    rt;
}
