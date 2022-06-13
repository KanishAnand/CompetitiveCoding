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

void solve() {
    lli n, a, x, b;
    cin >> n >> x;
    vector<lli> v;
    lli mx = -1;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mx = max(a, mx);
        v.pb(a);
    }

    lli p = mx, ans = 0;
    lli xx = x;

    while (p > 0 && xx > 0) {
        ans += p;
        p--;
        xx--;
    }

    for (lli i = 0; i < n; i++) {
        v.pb(v[i]);
    }
    v.pb(v[0]);
    // if (n > 1) {
    //     v.pb(v[1]);
    // }

    lli pp = v.size();
    vector<lli> pref(pp, 0), preff(pp, 0);
    pref[0] = (v[0] * (v[0] + 1)) / 2;
    preff[0] = v[0];

    for (lli i = 1; i < sz(v); i++) {
        pref[i] = pref[i - 1] + (v[i] * (v[i] + 1)) / 2;
        preff[i] = preff[i - 1] + v[i];
    }

    for (lli i = 1; i <= n; i++) {
        lli tmp = x;
        if (v[i] > x) {
            continue;
        } else {
            lli val = x + preff[i - 1];
            cout << val << endl;
            auto it = upper_bound(preff.begin(), preff.end(), val);
            lli ind = it - preff.begin();
            ind--;
            cout << ind << endl;
            lli no = pref[ind] - pref[i - 1];
            tmp = x - (preff[ind] - preff[i - 1]);
            a = v[i - 1];
            b = v[ind + 1];
            if (a >= b) {
                lli q = max((lli)0, a - tmp);
                no += ((a * (a + 1)) / 2) - (q * (q + 1)) / 2;
            } else {
                if (tmp >= a) {
                    no += (tmp * (tmp + 1)) / 2;
                } else {
                    lli q = max((lli)0, a - tmp);
                    no += (a * (a + 1)) / 2 - (q * (q + 1)) / 2;
                }
            }
            cout << no << endl;
            ans = max(ans, no);
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