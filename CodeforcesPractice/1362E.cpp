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
    lli n, a, p;
    cin >> n >> p;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    if (p == 1) {
        cout << n % 2 << endl;
        return;
    }

    sort(v.rbegin(), v.rend());

    map<lli, lli> mp1, mp2;
    lli flag = 1, no1;

    for (lli i = 0; i < n;) {
        lli val = v[i];
        flag = 1;
        no1 = i;
        mp1[val]++;
        lli j;
        for (j = i + 1; j < n; j++) {
            lli vv = v[j];
            lli ind = -1;
            mp2[vv]++;
            if (mp2[vv] == p) {
                ind = vv + 1;
                mp2[vv] = 0;
                mp2[ind]++;
                while (mp2[ind] == p) {
                    mp2[ind] = 0;
                    ind++;
                    mp2[ind]++;
                }
            }
            if (mp2[val] == 1) {
                mp2[val] = 0;
                mp1[val] = 0;
                flag = 0;
                break;
            }
        }
        i = j + 1;
    }

    lli ans = 0;
    if (flag == 1) {
        ans += power(p, v[no1]);
        for (lli i = no1 + 1; i < n; i++) {
            ans -= power(p, v[i]);
            ans += MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}