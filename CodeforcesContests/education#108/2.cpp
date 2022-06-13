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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, m, k;
    cin >> n >> m >> k;

    vector<vector<lli>> mn(n + 2, vector<lli>(m + 2, 1e9)), mx(n + 2, vector<lli>(m + 2, -1));
    mn[1][1] = 0;
    mx[1][1] = 0;

    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= m; j++) {
            if (i != n) {
                mn[i + 1][j] = min(mn[i + 1][j], mn[i][j] + j);
                mx[i + 1][j] = max(mx[i + 1][j], mx[i][j] + j);
            }
            if (j != m) {
                mn[i][j + 1] = min(mn[i][j + 1], mn[i][j] + i);
                mx[i][j + 1] = max(mx[i][j + 1], mx[i][j] + i);
            }
        }
    }

    if (k >= mn[n][m] && k <= mx[n][m]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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