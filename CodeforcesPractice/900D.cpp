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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
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

void solve() {
    lli x, y, ans = 0;
    cin >> x >> y;

    if (y % x != 0) {
        cout << "0" << endl;
        return;
    }

    y /= x;

    vector<lli> factors;

    lli pp = y;
    for (lli i = 2; i <= sqrt(pp); i++) {
        if (pp == 1) {
            break;
        }
        if (pp % i != 0) {
            continue;
        }
        factors.pb(i);
        while (pp % i == 0) {
            pp /= i;
        }
    }
    if (pp != 1) {
        factors.pb(pp);
    }

    ans += power(2, y - 1);
    ans %= MOD;

    lli tot = pow(2, sz(factors));
    for (lli mask = 1; mask < tot; mask++) {
        lli tmp = mask, cnt = 0, ind = 0, prod = 1;
        while (tmp > 0) {
            if (tmp % 2) {
                cnt++;
                prod *= factors[ind];
            }
            ind++;
            tmp /= 2;
        }

        if (cnt % 2) {
            ans -= power(2, y / prod - 1);
            ans += MOD;
            ans %= MOD;
        } else {
            ans += power(2, y / prod - 1);
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