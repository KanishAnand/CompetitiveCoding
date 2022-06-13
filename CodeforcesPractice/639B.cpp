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
    lli n, h, d;
    cin >> n >> d >> h;

    vector<pair<lli, lli>> ans;

    if (h > d || h > n - 1 || d > n - 1 || d > 2 * h) {
        cout << "-1" << endl;
        return;
    } else if (h == d) {
        for (lli i = 1; i <= h; i++) {
            ans.pb({i, i + 1});
        }
        lli p = h + 2;
        if (ans.size() != n - 1 && h == 1) {
            cout << "-1" << endl;
            return;
        }
        while (ans.size() != n - 1) {
            ans.pb({2, p});
            p++;
        }
    } else {
        for (lli i = 1; i <= h; i++) {
            ans.pb({i, i + 1});
        }
        lli p = h + 2, prev = 1;
        for (lli i = 1; i <= d - h; i++) {
            ans.pb({prev, p});
            prev = p;
            p++;
        }
        while (ans.size() != n - 1) {
            ans.pb({1, p});
            p++;
        }
    }

    for (lli i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
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