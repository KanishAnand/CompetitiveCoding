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
const lli MOD = 998244353;
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
    lli n, a, b;
    cin >> n;

    vector<lli> fac(n + 2, 1);
    for (lli i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    vector<lli> cnt1(n + 2, 0), cnt2(n + 2, 0);
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({a, b});
        cnt1[a]++;
        cnt2[b]++;
    }

    sort(all(v));

    lli tmp1 = 1, tmp2 = 1;

    for (lli i = 1; i <= n; i++) {
        if (cnt1[i] > 1) {
            tmp1 *= fac[cnt1[i]];
            tmp1 %= MOD;
        }
        if (cnt2[i] > 1) {
            tmp2 *= fac[cnt2[i]];
            tmp2 %= MOD;
        }
    }

    lli flag = 0;
    for (lli i = 1; i < n; i++) {
        if (v[i].second < v[i - 1].second) {
            flag = 1;
            break;
        }
    }

    lli tmp3 = 0;

    if (flag == 0) {
        lli cnt = 0;
        tmp3 = 1;
        for (lli i = 1; i < n; i++) {
            if ((v[i].first == v[i - 1].first) &&
                (v[i].second == v[i - 1].second)) {
                if (cnt == 0) {
                    cnt += 2;
                } else {
                    cnt++;
                }
            } else {
                if (cnt != 0) {
                    tmp3 *= fac[cnt];
                    tmp3 %= MOD;
                }
                cnt = 0;
            }
        }

        if (cnt != 0) {
            tmp3 *= fac[cnt];
            tmp3 %= MOD;
        }
    }

    lli ans = fac[n] - ((tmp1 + tmp2) % MOD - tmp3);
    ans += 2 * MOD;
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