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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> mp(72, 0);
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (mp[a] == 0) {
            v.pb(a);
        }
        mp[a]++;
    }

    // no of primes less than 70: 19
    vector<lli> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
    vector<lli> prev_dp(pow(2, 19), 0);
    prev_dp[0] = 1;

    vector<lli> store_mask(72, 0);
    for (lli i = 1; i <= 70; i++) {
        lli no = i, m = 1, current_mask = 0;
        for (auto p : primes) {
            lli cnt = 0;
            while (no % p == 0) {
                no /= p;
                cnt++;
            }
            if (cnt % 2) {
                current_mask += m;
            }
            m *= 2;
        }
        store_mask[i] = current_mask;
    }

    for (lli i = 0; i < sz(v); i++) {
        lli current_mask = store_mask[v[i]];
        // lli cnt_odd = ((mp[v[i]] + 1) / 2), cnt_even = (mp[v[i]] / 2) + 1;
        lli cnt_odd = power(2, mp[v[i]] - 1), cnt_even = power(2, mp[v[i]] - 1);
        vector<lli> dp(pow(2, 19), 0);

        for (lli mask = 0; mask < pow(2, 19); mask++) {
            lli new_mask = (mask ^ current_mask);
            dp[mask] += (prev_dp[mask] * cnt_even) % MOD;
            dp[mask] %= MOD;
            dp[new_mask] += (prev_dp[mask] * cnt_odd) % MOD;
            dp[new_mask] %= MOD;
        }
        prev_dp = dp;
    }

    lli ans = prev_dp[0] - 1;
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