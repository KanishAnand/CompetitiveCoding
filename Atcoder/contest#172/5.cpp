#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264338;
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

vector<lli> fac(1e6 + 2, 1), invfac(1e6 + 2, 1);

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
    if (r > n) {
        return 0;
    }
    lli ans = fac[n];
    lli val = (invfac[n - r] * invfac[r]) % MOD;
    ans *= val;
    ans %= MOD;
    return ans;
}

void solve() {
    for (lli i = 1; i <= 1e6; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        invfac[i] = inverseMod(fac[i]);
    }

    lli n, a, m;
    cin >> n >> m;

    lli ans = (nCr(m, n) * fac[n]) % MOD;
    ans *= ans;
    ans %= MOD;

    lli sub = 0;
    for (lli i = 1; i <= n; i++) {
        lli val = (nCr(n, i) * nCr(m, i)) % MOD;
        val *= fac[i];
        val %= MOD;
        lli p = (nCr(m - i, n - i) * fac[n - i]) % MOD;
        p *= p;
        p %= MOD;
        val *= p;
        val %= MOD;
        if (i % 2 == 0) {
            val = -val;
        }
        sub += val;
        sub += MOD;
        sub %= MOD;
    }

    ans = ans - sub;
    ans += MOD;
    ans %= MOD;
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