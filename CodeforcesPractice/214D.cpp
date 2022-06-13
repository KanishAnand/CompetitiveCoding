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

vector<lli> fac(102, 0);

lli inverseMod(lli a) {
    return power(a, MOD - 2);
}

lli nCr(lli n, lli r) {
    if (r > n) {
        return 0;
    }
    lli ans = fac[n];
    lli val = (inverseMod(fac[r]) * inverseMod(fac[n - r])) % MOD;
    ans *= val;
    ans %= MOD;
    return ans;
}

vector<vector<lli>> dp(102, vector<lli>(10, 0));

void solve() {
    fac[0] = 1;
    for (lli i = 1; i < 102; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    lli n, a;
    cin >> n;
    vector<lli> v;
    lli sum = 0;
    for (lli i = 0; i < 10; i++) {
        cin >> a;
        v.pb(a);
        sum += a;
    }

    if (sum > n) {
        cout << "0" << endl;
        return;
    }

    lli ans = 0;

    for (lli cnt = v[1]; cnt <= n; cnt++) {
        dp[cnt][1] = 1;
    }

    for (lli digit = 2; digit <= 9; digit++) {
        for (lli len = 0; len <= n; len++) {
            for (lli cnt = v[digit]; cnt <= len; cnt++) {
                dp[len][digit] +=
                    (nCr(len, cnt) * dp[len - cnt][digit - 1]) % MOD;
                dp[len][digit] %= MOD;
            }
        }
    }

    for (lli len = sum; len <= n; len++) {
        for (lli i = v[0]; i <= len; i++) {
            ans += (nCr(len - 1, i) * dp[len - i][9]) % MOD;
            ans %= MOD;
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