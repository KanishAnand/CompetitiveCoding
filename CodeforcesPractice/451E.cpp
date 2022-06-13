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

lli stars_bars(lli n, lli r) {
    lli ans = 1;
    for (lli i = 0; i < r - 1; i++) {
        ans *= (n + r - 1 - i) % MOD;
        ans %= MOD;
    }

    ans *= inverseMod(fac[r - 1]);
    ans %= MOD;
    return ans;
}

void solve() {
    lli n, a, s;
    cin >> n >> s;

    fac.resize(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli ans = 0;
    for (lli mask = 1; mask < pow(2, n); mask++) {
        lli cnt = 0, tmp = mask, base = 0, ind = 0;
        while (tmp > 0) {
            if (tmp % 2 == 1) {
                base += (v[ind] + 1);
                cnt++;
            }
            tmp /= 2;
            ind++;
        }

        if (base > s) {
            continue;
        }

        lli val = stars_bars(s - base, n);
        if (cnt % 2) {
            ans += val;
            ans %= MOD;
        } else {
            ans -= val;
            ans += MOD;
            ans %= MOD;
        }
    }

    lli total = stars_bars(s, n);
    ans = total - ans;
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