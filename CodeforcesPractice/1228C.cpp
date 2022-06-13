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
const lli MOD = 1e9 + 7;
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

void solve() {
    lli n, a, x;
    cin >> x >> n;
    vector<lli> prime;

    for (lli i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            prime.pb(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }

    if (x != 1) {
        prime.pb(x);
    }

    lli ans = 1;

    for (lli i = 0; i < prime.size(); i++) {
        lli val = 1, prev;
        for (lli j = 0; j <= 60; j++) {
            lli no = n / val;
            prev = val;
            no = no - no / prime[i];
            if (no <= 0) {
                break;
            }
            ans *= power(val, no);
            ans %= MOD;
            val *= prime[i];
            if (val / prime[i] != prev) {
                break;
            }
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