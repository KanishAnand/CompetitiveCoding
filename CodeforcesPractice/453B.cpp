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
const double PI = 3.14159265358979323846264338;
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

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                          29, 31, 37, 41, 43, 47, 53, 59};

    vector<vector<lli>> fac(62);
    for (lli i = 0; i < sz(primes); i++) {
        for (lli j = 1; j < 60; j++) {
            if (j % primes[i] == 0) {
                fac[j].pb(primes[i]);
            }
        }
    }

    map<lli, lli> mp;

    for (lli i = 0; i < sz(primes); i++) {
        mp[primes[i]] = i;
    }

    lli lim = (1ll << 17);
    vector<vector<lli>> dp(n + 2, vector<lli>(lim + 2, 1e10));

    // BASE CASE
    for (lli no = 1; no < 60; no++) {
        lli val = abs(no - v[0]);
        lli bits = 0;
        for (lli j = 0; j < fac[no].size(); j++) {
            lli p = mp[fac[no][j]];
            lli q = (1ll << p);
            bits += q;
        }
        dp[0][bits] = min(dp[0][bits], val);
    }

    for (lli i = 1; i < n; i++) {
        for (lli no = 1; no < 60; no++) {
            lli val = abs(no - v[i]);
            lli bits = 0;
            for (lli j = 0; j < fac[no].size(); j++) {
                lli p = mp[fac[no][j]];
                lli q = (1ll << p);
                bits += q;
            }
            for (lli mask = 0; mask < lim; mask++) {
                if ((mask & bits) == 0) {
                    lli new_mask = (mask | bits);
                    dp[i][new_mask] =
                        min(dp[i][new_mask], dp[i - 1][mask] + val);
                }
            }
        }
    }

    lli ans = 1e10;
    lli store_mask;
    for (lli mask = 0; mask < lim; mask++) {
        if (dp[n - 1][mask] < ans) {
            store_mask = mask;
        }
        ans = min(ans, dp[n - 1][mask]);
    }

    // BACKTRACK

    vector<lli> store_ans;

    for (lli i = n - 1; i > 0; i--) {
        for (lli no = 1; no < 60; no++) {
            lli val = abs(no - v[i]);
            lli bits = 0;
            for (lli j = 0; j < fac[no].size(); j++) {
                lli p = mp[fac[no][j]];
                lli q = (1ll << p);
                bits += q;
            }
            lli req = ans - val;
            lli p = (store_mask & bits);
            if (p != bits) {
                continue;
            }
            lli new_mask = (store_mask ^ bits);
            if (dp[i - 1][new_mask] == req) {
                store_ans.pb(no);
                ans -= val;
                store_mask = new_mask;
                break;
            }
        }
    }

    lli last;
    for (lli no = 59; no >= 1; no--) {
        lli bits = 0;
        lli valu = abs(v[0] - no);
        for (lli j = 0; j < fac[no].size(); j++) {
            lli p = mp[fac[no][j]];
            lli q = (1ll << p);
            bits += q;
        }
        lli p = (store_mask & bits);
        if (p != bits) {
            continue;
        } else {
            if (valu == ans) {
                last = no;
                break;
            }
        }
    }

    store_ans.pb(last);

    reverse(all(store_ans));
    for (lli i = 0; i < n; i++) {
        cout << store_ans[i] << " ";
    }
    cout << endl;
    // cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}