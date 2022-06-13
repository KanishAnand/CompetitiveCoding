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

void solve() {
    lli n, a, m, k;
    cin >> n >> m >> k;

    vector<lli> flag(n + m + 2, 0);
    vector<double> sum(n + m + 2, 0), var(n + m + 2, 0);

    for (lli i = 0; i < k; i++) {
        cin >> a;
        flag[a] = 1;
    }

    lli last = n + m;
    double tot = 0, cnt = 0, rev_m = (1.0 / m);

    for (lli i = n - 1; i >= 0; i--) {
        tot = tot + sum[i + 1] - sum[last];
        cnt = cnt + var[i + 1] - var[last];
        last--;
        if (flag[i] == 1) {
            sum[i] = 0;
            var[i] = 1;
        } else {
            sum[i] = 1 + rev_m * tot;
            var[i] = rev_m * cnt;
        }
    }

    double p = 1 - var[0];
    if (p < 1e-9) {
        cout << "-1" << endl;
        return;
    }
    double ans = sum[0] / p;
    cout << fixed << setprecision(10);
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