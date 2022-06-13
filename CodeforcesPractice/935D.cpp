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
    lli n, m, a;
    cin >> n >> m;
    vector<lli> st1, st2;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        st1.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        st2.pb(a);
    }

    lli ans = 0, p = 1, val;
    lli inv_m = inverseMod(m);

    for (lli i = 0; i < n; i++) {
        if (st1[i] != 0 && st2[i] != 0) {
            if (st1[i] < st2[i]) {
                break;
            } else if (st1[i] > st2[i]) {
                ans += p;
                ans %= MOD;
                break;
            } else {
                continue;
            }
        } else if (st1[i] == 0 && st2[i] == 0) {
            val = (m * (m - 1)) / 2;
            val *= p;
            val %= MOD;
            val *= inv_m;
            val %= MOD;
        } else if (st1[i] == 0) {
            val = (p * (m - st2[i])) % MOD;

        } else {
            val = (p * (st1[i] - 1)) % MOD;
        }
        val *= inv_m;
        val %= MOD;
        ans += val;
        ans %= MOD;
        p *= inv_m;
        p %= MOD;
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