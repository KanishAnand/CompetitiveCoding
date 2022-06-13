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
    lli n, a, m, mx = -1, ind = -1;
    cin >> n >> m;

    lli x, k, y;
    cin >> x >> k >> y;

    vector<lli> va, vb;
    map<lli, lli> mp, mp2;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a > mx) {
            mx = a;
            ind = i;
        }
        mp[a] = i + 1;
        va.pb(a);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a;
        mp2[a] = i + 1;
        vb.pb(a);
    }

    if (sz(vb) > sz(va)) {
        cout << "-1" << endl;
        return;
    }

    lli prev = 0;
    for (lli i = 0; i < m; i++) {
        lli val = mp[vb[i]];
        if (val == 0) {
            cout << "-1" << endl;
            return;
        }
        if (val < prev) {
            cout << "-1" << endl;
            return;
        }
        prev = val;
    }

    lli cnt = 0;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        if (mp2[va[i]] != 0) {
            if (cnt != 0) {
                v.pb(cnt);
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (cnt != 0) {
        v.pb(cnt);
    }

    lli ans = 0;

    for (auto val : v) {
        lli val1 = (val / k) * x + (val % k) * y;
        lli val2 = val * y;
        ans += min(val1, val2);
    }

    cout << ans << endl;

    if (mp2[mx] == 0) {
        lli p = ind;
        while (p >= 0) {
            if (mp2[va[p]] == 0) {
                p--;
            } else {
                break;
            }
        }
        lli q = ind;
        while (q < n) {
            if (mp2[va[q]] == 0) {
                q++;
            } else {
                break;
            }
        }

        q--;
        p++;
        lli range = q - p + 1;
        lli val1 = (range / k) * x + (range % k) * y;
        lli val2 = range * y;
        ans -= min(val1, val2);
        if (range < k) {
            cout << "-1" << endl;
            return;
        }
        range -= k;
        ans += x;
        val1 = (range / k) * x + (range % k) * y;
        val2 = range * y;
        ans += min(val1, val2);
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