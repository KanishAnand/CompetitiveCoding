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
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
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

vector<lli> fac(105, 1), invfac(105, 1);

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

lli nCr(lli n, lli r) {
    if (r > n) {
        return 0;
    }

    lli ans = 1;
    for (lli i = n; i > n - r; i--) {
        ans *= i;
        ans %= MOD;
    }

    ans *= invfac[r];
    ans %= MOD;
    return ans;
}

lli inverseMod(lli a) {
    return power(a, MOD - 2);
}

void solve() {
    lli n, a, m, k;
    cin >> n >> m >> k;

    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    sort(all(v));

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        lli val = v[i] + k;
        auto it = upper_bound(v.begin(), v.end(), val);
        lli ind;
        if (it == v.end()) {
            ind = n - 1;
        } else {
            ind = it - v.begin();
            ind--;
        }
        lli no = ind - i;
        ans += nCr(no, m - 1);
        ans %= MOD;
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (lli i = 1; i <= 101; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        invfac[i] = inverseMod(fac[i]);
    }

    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}