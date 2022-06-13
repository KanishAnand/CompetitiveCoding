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
// const lli MOD = 1e9 + 7;
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
    // x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            // ans %= MOD;
        }
        y = y >> 1;
        x = (x * x);
    }
    return ans;
}

void solve() {
    lli n, a;
    cin >> n;
    string st = "codeforces";
    lli tmp = n, cnt;

    for (lli i = 1;; i++) {
        lli val = power(i, 10);
        if (val <= n) {
            cnt = i;
        } else {
            break;
        }
    }

    lli val = power(cnt, 10);
    lli on = n;
    n -= val;
    lli no = 0;

    while (n > 0) {
        val /= cnt;
        val *= (cnt + 1);
        no++;
        if (val >= on) {
            break;
        }
        n = on - val;
    }

    string ans = "";

    for (lli i = 0; i < 10; i++) {
        for (lli j = 0; j < cnt; j++) {
            ans += st[i];
        }
        if (no > 0) {
            no--;
            ans += st[i];
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