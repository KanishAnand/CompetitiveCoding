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

lli check(lli l, lli r, vector<lli> &c, vector<lli> &a, vector<lli> &b, vector<lli> &dp_start, vector<lli> &dp_end) {
    dp_start[l] = abs(a[l + 1] - b[l + 1]);
    for (lli i = l + 1; i < r; i++) {
        lli cur = abs(a[i + 1] - b[i + 1]);
        lli prev = dp_start[i - 1] + 2 + c[i] - 1 - abs(a[i + 1] - b[i + 1]);
        dp_start[i] = max(cur, prev);
    }

    dp_end[r] = c[r] - 1;

    for (lli i = r - 1; i >= l; i--) {
        lli cur = c[i] - 1;
        lli prev = dp_end[i + 1] + 2 + c[i] - 1 - abs(a[i + 1] - b[i + 1]);
        dp_end[i] = max(cur, prev);
    }

    lli ans = 0;
    for (lli i = l; i < r; i++) {
        // cout << dp_start[i] << " " << i << endl;
        // cout << dp_end[i + 1] << " " << i + 1 << endl;
        lli val = dp_start[i] + dp_end[i + 1] + 2;
        ans = max(ans, val);
    }
    return ans;
}

void solve() {
    lli n, p;
    cin >> n;
    vector<lli> c;
    for (lli i = 0; i < n; i++) {
        cin >> p;
        c.pb(p);
    }

    vector<lli> a, b;
    for (lli i = 0; i < n; i++) {
        cin >> p;
        a.pb(p);
    }
    for (lli i = 0; i < n; i++) {
        cin >> p;
        b.pb(p);
    }

    vector<lli> split;
    split.pb(0);
    for (lli i = 1; i < n; i++) {
        if (a[i] == b[i] && i != 1) {
            split.pb(i - 1);
        }
    }
    split.pb(n - 1);

    vector<lli> dp_start(n + 2, 0), dp_end(n + 2, 0);
    lli ans = -1;
    for (lli i = 1; i < sz(split); i++) {
        lli no = check(split[i - 1], split[i], c, a, b, dp_start, dp_end);
        ans = max(ans, no);
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