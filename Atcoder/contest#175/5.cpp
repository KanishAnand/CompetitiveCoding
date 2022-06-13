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

lli r, c, k;
vector<vector<lli>> v, dp;

lli fun(lli x, lli y) {
    if (x >= r) {
        return 0;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    lli mx1 = 0, mx2 = 0, mx3 = 0;
    lli val = 0;
    // vector<lli> store;

    cout << x << " " << y << endl;
    for (lli i = c - 1; i >= y; i--) {
        if (v[x][i] > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = v[x][i];
        } else if (v[x][i] > mx2) {
            mx3 = mx2;
            mx2 = v[x][i];
        } else {
            mx3 = v[x][i];
        }

        lli no = mx1 + mx2 + mx3;
        val = max(val, no + fun(x + 1, i));
        dp[x][i] = val;
        cout << no << " " << x << " " << i << " " << val << endl;
    }

    // for (lli i = y; i < c; i++) {
    //     // cout << x << " " << i << endl;
    //     if (v[x][i] > mx1) {
    //         mx3 = mx2;
    //         mx2 = mx1;
    //         mx1 = v[x][i];
    //     } else if (v[x][i] > mx2) {
    //         mx3 = mx2;
    //         mx2 = v[x][i];
    //     } else {
    //         mx3 = v[x][i];
    //     }

    //     lli no = mx1 + mx2 + mx3;
    //     lli val = no + fun(x + 1, i);
    //     store.pb(val);
    // }

    // reverse(all(store));

    // lli mx = 0, beg = 0;
    // for (lli i = c - 1; i >= y; i--) {
    //     mx = max(mx, store[beg]);
    //     dp[x][i] = mx;
    //     cout << x << " " << i << " " << dp[x][i] << endl;
    //     beg++;
    // }

    // dp[x][y] = val;
    return dp[x][y];
}

void solve() {
    cin >> r >> c >> k;
    v.resize(r + 2, vector<lli>(c + 2, 0));
    dp.resize(r + 2, vector<lli>(c + 2, -1));

    lli x, y, val;

    for (lli i = 0; i < k; i++) {
        cin >> x >> y >> val;
        x--;
        y--;
        v[x][y] = val;
    }

    dp[0][0] = fun(0, 0);
    cout << dp[0][0] << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}