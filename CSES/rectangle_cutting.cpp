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

vector<vector<lli>> dp;

lli fun(lli a, lli b) {
    lli val = 1e10;
    if (a == b) {
        dp[a][a] = 0;
        return 0;
    }
    if (dp[a][b] != -1) {
        return dp[a][b];
    }

    for (lli i = 1; i <= a - 1; i++) {
        lli val2 = fun(i, b) + fun(a - i, b);
        val = min(val, val2 + 1);
    }
    for (lli i = 1; i <= b - 1; i++) {
        lli val2 = fun(a, i) + fun(a, b - i);
        val = min(val, val2 + 1);
    }
    dp[a][b] = val;
    dp[b][a] = val;
    return val;
}

void solve() {
    lli a, b;
    cin >> a >> b;
    lli p = max(a, b);
    dp.resize(p + 2, vector<lli>(p + 2, -1));
    cout << fun(a, b) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}