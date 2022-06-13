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

vector<lli> fac;

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
    lli val = (inverseMod(fac[n - r]) * inverseMod(fac[r])) % MOD;
    val = (val * fac[n]) % MOD;
    return val;
}

void solve() {
    lli n, a, m, k;
    cin >> n >> m >> k;

    fac.resize(n + 2, 0);
    fac[0] = 1;
    for (lli i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    lli val = max((lli)1, n - k);
    lli ans = 0;

    for (lli i = val; i <= n; i++) {
        lli p = power(m - 1, i - 1);
        p *= m;
        p %= MOD;
        p *= nCr(n - 1, i - 1);
        p %= MOD;
        ans += p;
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