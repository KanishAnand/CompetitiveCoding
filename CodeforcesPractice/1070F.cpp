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
    lli n, a;
    cin >> n;
    string st;
    vector<lli> v1, v2, v3, v4;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        cin >> a;
        if (st == "00") {
            v1.pb(a);
        } else if (st == "01") {
            v2.pb(a);
        } else if (st == "10") {
            v3.pb(a);
        } else {
            v4.pb(a);
        }
    }

    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    sort(v3.rbegin(), v3.rend());
    sort(v4.rbegin(), v4.rend());

    vector<lli> pref1(n + 2, 0), pref2(n + 2, 0), pref3(n + 2, 0),
        pref4(n + 2, 0);

    lli tot = 0, cnt = v4.size();

    for (lli i = 0; i < v1.size(); i++) {
        pref1[i + 1] = pref1[i] + v1[i];
    }
    for (lli i = 0; i < v2.size(); i++) {
        pref2[i + 1] = pref2[i] + v2[i];
    }
    for (lli i = 0; i < v3.size(); i++) {
        pref3[i + 1] = pref3[i] + v3[i];
    }
    for (lli i = 0; i < v4.size(); i++) {
        tot += v4[i];
        pref4[i + 1] = pref4[i] + v4[i];
    }

    lli b;
    lli ans = -1;

    for (lli i = 0; i <= v1.size(); i++) {
        lli val = tot + pref1[i];

        lli m = min(sz(v2), sz(v3));
        val += pref2[m];
        val += pref3[m];

        n = 2 * (m + cnt);

        lli rem = n - cnt - i - 2 * m;

        if (rem < 0) {
            continue;
        }

        a = sz(v2) - m;
        b = sz(v3) - m;

        if (a != 0) {
            lli p = min(rem + m, sz(v2));
            val += pref2[p] - pref2[m];
        }
        if (b != 0) {
            lli p = min(rem + m, sz(v3));
            val += pref3[p] - pref3[m];
        }

        ans = max(ans, val);
    }

    if (ans == -1) {
        cout << "0" << endl;
    } else {
        cout << ans << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}