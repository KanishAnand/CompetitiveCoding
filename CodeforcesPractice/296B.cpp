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
    lli n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;

    lli type1 = 0, type2 = 0, type3 = 0;
    lli tot = 0;

    for (lli i = 0; i < n; i++) {
        if (s[i] == '?') {
            tot++;
        }
        if (t[i] == '?') {
            tot++;
        }
        if (s[i] != '?' && t[i] != '?') {
            if (s[i] < t[i]) {
                type1 = 1;
                type3 = 1;
            } else if (t[i] < s[i]) {
                type2 = 1;
                type3 = 1;
            }
        }
    }

    lli a = 0, b = 0, c = 0;
    if (type3 != 1) {
        c = 1;
        for (lli i = 0; i < n; i++) {
            if (s[i] == '?' && t[i] == '?') {
                c *= 10;
                c %= MOD;
            }
        }
    }

    if (type1 != 1) {
        a = 1;
        for (lli i = 0; i < n; i++) {
            if (s[i] == '?' && t[i] == '?') {
                a *= 55;
                a %= MOD;
            } else if (s[i] == '?') {
                lli val = t[i] - '0';
                val = 9 - val + 1;
                a *= val;
                a %= MOD;
            } else if (t[i] == '?') {
                lli val = s[i] - '0';
                val = val + 1;
                a *= val;
                a %= MOD;
            }
        }
    }

    if (type2 != 1) {
        b = 1;
        for (lli i = 0; i < n; i++) {
            if (s[i] == '?' && t[i] == '?') {
                b *= 55;
                b %= MOD;
            } else if (t[i] == '?') {
                lli val = s[i] - '0';
                val = 9 - val + 1;
                b *= val;
                b %= MOD;
            } else if (s[i] == '?') {
                lli val = t[i] - '0';
                val = val + 1;
                b *= val;
                b %= MOD;
            }
        }
    }

    lli ans = power(10, tot);
    lli val = (a + b) % MOD;
    val -= c;
    val += MOD;
    val %= MOD;
    ans -= val;
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