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

vector<lli> fac(1e5 + 5, 0);
vector<lli> invfac(1e5 + 5, 0);

lli power(lli x, lli y) {
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

lli modInverse(lli n) {
    return power(n, MOD - 2) % MOD;
}

lli fun(lli n, lli r) {
    if (r == 0) {
        return 1;
    }
    lli val2 = (invfac[n - r] * invfac[r]) % MOD;
    lli val = (fac[n] * val2) % MOD;
    return val;
}

void solve() {
    lli n, a, q;
    cin >> n;

    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    cin >> q;
    lli l, r;

    while (q--) {
        cin >> l >> r;
        l--;
        r--;
        map<lli, lli> mp;
        for (lli i = l; i <= r; i++) {
            mp[v[i]]++;
        }

        lli xr = 0, ans = 0;
        for (auto it : mp) {
            xr ^= it.second;
        }

        lli prevxr = xr;
        for (auto it : mp) {
            lli val = it.second;
            xr ^= val;
            // cout << it.first << " " << it.second << endl;
            // cout << xr << endl;
            if (xr < val) {
                ans += fun(val, val - xr);
                ans %= MOD;
            }
            xr = prevxr;
        }
        cout << ans << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1;
    for (lli i = 1; i <= 1e5 + 5; i++) {
        fac[i] = (i * fac[i - 1]) % MOD;
    }

    for (lli i = 0; i <= 1e5 + 5; i++) {
        invfac[i] = modInverse(fac[i]);
    }

    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    rt;
}