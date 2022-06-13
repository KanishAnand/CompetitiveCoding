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

    vector<lli> v;
    map<lli, lli> mp;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (mp[a] == 0) {
            v.pb(a);
        }
        mp[a]++;
    }

    vector<lli> pref(sz(v) + 2, 1), suff(sz(v) + 2, 1);

    for (lli i = 1; i < sz(v); i++) {
        pref[i] = (pref[i - 1] * (1 + mp[v[i - 1]])) % (MOD - 1);
    }

    for (lli i = sz(v) - 2; i >= 0; i--) {
        suff[i] = (suff[i + 1] * (1 + mp[v[i + 1]])) % (MOD - 1);
    }

    lli ans = 1;
    for (lli i = 0; i < v.size(); i++) {
        lli p = mp[v[i]];
        lli pp = (p * (p + 1)) / 2;
        lli val = power(v[i], pp);
        val = power(val, suff[i]);
        val = power(val, pref[i]);
        ans *= val;
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