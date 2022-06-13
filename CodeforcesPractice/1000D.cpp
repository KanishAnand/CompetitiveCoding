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
const lli MOD = 998244353;
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

vector<lli> fac(1005, 1);

lli power(lli x, lli y) {
    // log y complexity
    // return (x^y) % MOD
    lli ans = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return ans;
}

lli inverseMod(lli a) {
    return power(a, MOD - 2);
}

lli nCr(lli n, lli r) {
    if (n < 0) {
        return 0;
    }
    if (r > n) {
        return 0;
    }
    lli ans = fac[n];
    lli val = (inverseMod(fac[n - r]) * inverseMod(fac[r])) % MOD;
    ans *= val;
    ans %= MOD;
    return ans;
}

void solve() {
    for (lli i = 1; i < 1003; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> dp(n + 2, 0);

    if (v[0] > 0) {
        for (lli i = v[0]; i < n; i++) {
            lli val = nCr(i - 1, v[0] - 1);
            dp[i] += val;
            dp[i] %= MOD;
        }
    }

    lli val = dp[0];
    for (lli i = 1; i < n; i++) {
        if (v[i] > 0) {
            for (lli j = i + v[i]; j < n; j++) {
                lli p = (val + 1) % MOD;
                p *= nCr(j - i - 1, v[i] - 1);
                dp[j] += p;
                dp[j] %= MOD;
            }
        }
        val += dp[i];
        val %= MOD;
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        ans += dp[i];
        ans %= MOD;
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