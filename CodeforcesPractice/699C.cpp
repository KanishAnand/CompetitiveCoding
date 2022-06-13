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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    vector<vector<lli>> dp(n + 2, vector<lli>(4, 200));

    dp[0][0] = 1;
    if (v[0] == 3) {
        dp[0][1] = 0;
        dp[0][2] = 0;
    } else if (v[0] != 0) {
        dp[0][v[0]] = 0;
    }

    for (lli i = 1; i < n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (v[i] == 1) {
            dp[i][1] = min({dp[i - 1][0], dp[i - 1][2]});
        } else if (v[i] == 2) {
            dp[i][2] = min({dp[i - 1][0], dp[i - 1][1]});
        } else if (v[i] == 3) {
            dp[i][1] = min({dp[i - 1][0], dp[i - 1][2]});
            dp[i][2] = min({dp[i - 1][0], dp[i - 1][1]});
        }
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}