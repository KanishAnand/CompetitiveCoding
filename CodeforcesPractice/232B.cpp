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

lli inverse(lli a) {
    return power(a, MOD - 2);
}

void solve() {
    lli n, a, m, k;
    cin >> n >> m >> k;
    vector<lli> fac(n + 5, 1);
    vector<vector<lli>> dp(n + 5, vector<lli>(k + 5, 0));

    for (lli i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    vector<lli> nCr1(n + 5), nCr2(n + 5);
    nCr1[0] = 1;
    nCr2[0] = 1;

    lli val1 = m / n, val2 = (m / n) + 1;

    for (lli i = 1; i <= n; i++) {
        lli val = (inverse(fac[i]) * inverse(fac[n - i])) % MOD;
        nCr1[i] = (fac[n] * val) % MOD;
        nCr2[i] = nCr1[i];
        nCr1[i] = power(nCr1[i], val1);
        nCr2[i] = power(nCr2[i], val2);
    }

    for (lli i = 0; i <= min(n, k); i++) {
        if (m % n >= 1) {
            dp[1][i] = nCr2[i];
        } else {
            dp[1][i] = nCr1[i];
        }
    }

    for (lli i = 2; i <= n; i++) {
        for (lli j = 0; j <= n; j++) {
            for (lli p = 0; p <= k; p++) {
                if (j + p <= k) {
                    if (m % n >= i) {
                        dp[i][j + p] += (dp[i - 1][p] * nCr2[j]) % MOD;
                    } else {
                        dp[i][j + p] += (dp[i - 1][p] * nCr1[j]) % MOD;
                    }
                    dp[i][j + p] %= MOD;
                }
            }
        }
    }

    cout << dp[n][k] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}