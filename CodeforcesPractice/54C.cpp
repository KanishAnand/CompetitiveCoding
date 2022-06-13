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

double fun(lli l, lli r) {
    lli store_l = l, store_r = r;
    double den = r - l + 1;

    lli dig1, cnt1 = 0;
    while (l > 0) {
        dig1 = l % 10;
        cnt1++;
        l /= 10;
    }

    lli dig2, cnt2 = 0;
    while (r > 0) {
        dig2 = r % 10;
        cnt2++;
        r /= 10;
    }

    lli val = 0;
    for (lli i = cnt1 + 1; i <= cnt2 - 1; i++) {
        val += pow(10, i - 1);
    }

    lli tmp = min(store_r, (lli)(2 * pow(10, cnt1 - 1)) - 1) - store_l + 1;
    lli p = max(0ll, tmp);

    tmp = pow(10, cnt2 - 1);

    if (dig2 != 1) {
        lli no = 2 * tmp - 1;
        lli q = min(no - tmp + 1, no - store_l + 1);
        q = max(0ll, q);
        p += q;
    } else {
        p += min(store_r - tmp + 1, store_r - store_l + 1);
    }
    if (cnt1 == cnt2) {
        p /= 2;
    }

    val += p;
    double num = val;
    double ans = (num / den);
    return ans;
}

void solve() {
    // lli a, b;
    // while (1) {
    //     cin >> a >> b;
    //     fun(a, b);
    // }
    lli n, k, l, r;
    cin >> n;
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> l >> r;
        v.pb({l, r});
    }

    cin >> k;

    vector<double> prevdp(n + 5, 0);
    double one = fun(v[0].first, v[0].second);
    prevdp[0] = 1.0 - one;
    prevdp[1] = one;

    for (lli i = 1; i < n; i++) {
        vector<double> dp(n + 5, 0);
        double one = fun(v[i].first, v[i].second);
        for (lli j = 0; j <= n; j++) {
            dp[j] += prevdp[j] * (1.0 - one);
            dp[j + 1] += prevdp[j] * one;
        }
        prevdp = dp;
    }

    lli cnt = (n * k) / 100;
    if ((n * k) % 100 != 0) {
        cnt++;
    }

    double ans = 0;
    for (lli i = cnt; i <= n; i++) {
        ans += prevdp[i];
    }

    cout << fixed << setprecision(10);
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