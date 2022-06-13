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
int dp[5002][5002][2];

void solve() {
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (lli len = 2; len <= n; len++) {
        for (lli i = 0; i < n - len + 1; i++) {
            lli start = i, end = i + len - 1;
            lli val1 = dp[start + 1][end][0];
            if (v[start] != v[start + 1]) {
                val1++;
            }
            lli val2 = dp[start + 1][end][1];
            if (v[start] != v[end]) {
                val2++;
            }
            dp[start][end][0] = min(val1, val2);

            lli val11 = dp[start][end - 1][0];
            if (v[end] != v[start]) {
                val11++;
            }
            lli val22 = dp[start][end - 1][1];
            if (v[end] != v[end - 1]) {
                val22++;
            }
            dp[start][end][1] = min(val11, val22);
        }
    }

    cout << (lli)(min(dp[0][n - 1][0], dp[0][n - 1][1])) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}