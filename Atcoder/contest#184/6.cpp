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

void solve() {
    lli n, a, t;
    cin >> n >> t;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli ans = 0;

    if (n <= 20) {
        for (lli i = 0; i < pow(2, n); i++) {
            lli tmp = i, val = 0, cnt = 0;
            while (tmp > 0) {
                if (tmp % 2) {
                    val += v[cnt];
                }
                tmp /= 2;
                cnt++;
            }
            if (val <= t) {
                ans = max(ans, val);
            }
        }
        cout << ans << endl;
        return;
    }

    vector<lli> store1, store2;

    for (lli i = 0; i < pow(2, 20); i++) {
        lli tmp = i, val = 0, cnt = 0;
        while (tmp > 0) {
            if (tmp % 2) {
                val += v[cnt];
            }
            tmp /= 2;
            cnt++;
        }
        if (val <= t) {
            store1.pb(val);
        }
    }

    for (lli i = 0; i < pow(2, n - 20); i++) {
        lli tmp = i, val = 0, cnt = 20;
        while (tmp > 0) {
            if (tmp % 2) {
                val += v[cnt];
            }
            tmp /= 2;
            cnt++;
        }
        if (val <= t) {
            store2.pb(val);
        }
    }

    sort(all(store2));

    for (lli i = 0; i < sz(store1); i++) {
        lli val = store1[i];
        auto it = upper_bound(store2.begin(), store2.end(), t - val);
        lli ind = it - store2.begin();
        ind--;
        if (it == store2.end()) {
            ind = sz(store2) - 1;
        }
        if (ind >= 0) {
            val += store2[ind];
        }
        ans = max(ans, val);
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