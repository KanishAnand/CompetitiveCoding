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
const lli MOD = 998244353;
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

void solve() {
    lli n, a, sum = 0;
    cin >> n;
    vector<lli> v;

    for (lli i = 0; i < 2 * n; i++) {
        cin >> a;
        v.pb(a);
        sum += a;
    }

    sort(all(v));

    lli p = 0;
    for (lli i = 0; i < n; i++) {
        p += v[i];
    }

    sum -= 2 * p;
    sum %= MOD;

    lli num = 1;
    for (lli i = 2 * n; i >= n + 1; i--) {
        num *= i;
        num %= MOD;
    }
    lli denom = 1;
    for (lli i = n; i >= 1; i--) {
        denom *= i;
        denom %= MOD;
    }

    num *= inverseMod(denom);
    num %= MOD;

    sum *= num;
    sum %= MOD;

    cout << sum << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}