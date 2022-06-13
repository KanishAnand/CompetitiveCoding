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
    lli len, a;
    string st;
    cin >> st;

    reverse(all(st));
    len = st.length();

    lli inv_two = inverseMod(2);
    lli inv_nine = inverseMod(9);
    lli inv_ten = inverseMod(10);

    lli tenbynine = (10 * inv_nine) % MOD;

    lli ans = 0;

    for (lli i = 0; i < len; i++) {
        lli n = i;

        // calc gp
        lli gp_sum = 0;

        if (n != 0) {
            gp_sum = 1 - power(inv_ten, n - 1);
            gp_sum += 2 * MOD;
            gp_sum %= MOD;

            gp_sum *= tenbynine;
            gp_sum %= MOD;

            gp_sum *= inv_ten;
            gp_sum %= MOD;
            gp_sum *= inv_ten;
            gp_sum %= MOD;
        }

        // calc first two terms
        lli firstwo = (n * inv_ten) % MOD;
        lli firstwo2 = power(inv_ten, n + 1);
        firstwo -= firstwo2;
        firstwo += MOD;
        firstwo %= MOD;

        // calc final
        lli finl = firstwo - gp_sum;
        finl += MOD;
        finl %= MOD;

        lli s = finl * tenbynine;
        s %= MOD;

        if (n == 0) {
            s = 0;
        }

        // calc due to suffix
        lli rem = len - 1 - i;
        lli suff = (rem * (rem + 1)) % MOD;
        suff *= inv_two;
        suff %= MOD;

        lli full = (s + suff) % MOD;

        // mul with dig
        full *= (st[i] - '0');
        full %= MOD;

        // mul with power of 10
        lli pow_n = power(10, i);
        full *= pow_n;
        full %= MOD;

        ans += full;
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