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

vector<lli> fac(1e6 + 202, 1), invfac(1e6 + 202, 0);

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
    lli x, y;
    cin >> x >> y;
    set<lli> v;
    map<lli, lli> mp;

    for (lli i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            x /= i;
            v.insert(i);
            mp[i]++;
        }
    }

    if (x != 1) {
        v.insert(x);
        mp[x]++;
    }

    lli ans = 1;

    for (auto vv : v) {
        lli val1 = y + mp[vv] - 1;
        lli val2 = mp[vv];
        lli no = nCr(val1, val2);
        ans *= no;
        ans %= MOD;
    }

    lli fin = (ans * power(2, y - 1)) % MOD;

    cout << fin << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (lli i = 1; i <= 1e6 + 200; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    for (lli i = 0; i <= 1e6 + 200; i++) {
        invfac[i] = inverseMod(fac[i]);
    }

    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}