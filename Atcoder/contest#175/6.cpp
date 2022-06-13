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

void solve() {
    cin >> r >> c >> k;
    v.resize(r + 2, vector<lli>(c + 2, 0));
    dp.resize(r + 2, vector<lli>(c + 2, 0));

    lli x, y, val;

    for (lli i = 0; i < k; i++) {
        cin >> x >> y >> val;
        x--;
        y--;
        v[x][y] = val;
    }

    lli mx1 = 0, mx2 = 0, mx3 = 0;

    for (lli i = c - 1; i >= 0; i--) {
        if (v[r - 1][i] > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = v[r - 1][i];
        } else if (v[r - 1][i] > mx2) {
            mx3 = mx2;
            mx2 = v[r - 1][i];
        } else if (v[r - 1][i] > mx3) {
            mx3 = v[r - 1][i];
        }
        dp[r - 1][i] = mx1 + mx2 + mx3;
    }

    for (lli i = r - 2; i >= 0; i--) {
        multiset<lli> st;
        for (lli j = 0; j < c; j++) {
            st.insert(v[i][j]);
        }
        for (lli j = c - 1; j >= 0; j--) {
            auto it = st.end();
            it--;
            lli no = *it;
            if (st.size() >= 2) {
                it--;
                no += *it;
            }
            if (st.size() >= 3) {
                it--;
                no += *it;
            }
            dp[i][j] = max(dp[i][j + 1], no + dp[i + 1][j]);
            auto itt = st.lower_bound(v[i][j]);
            st.erase(itt);
        }
    }

    cout << dp[0][0] << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}