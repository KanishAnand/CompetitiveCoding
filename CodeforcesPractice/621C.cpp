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
    lli n, a, p, b;
    cin >> n >> p;
    vector<lli> no, tot;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        lli val = b / p - (a - 1) / p;
        lli total = b - a + 1;
        no.pb(val);
        tot.pb(total);
    }

    double ans = 0;

    for (lli i = 0; i < n - 1; i++) {
        double val = (tot[i] - no[i]) * (tot[i + 1] - no[i + 1]);
        val = val / (tot[i] * tot[i + 1]);
        val = 1.0 - val;
        ans += val;
    }

    double val = (tot[n - 1] - no[n - 1]) * (tot[0] - no[0]);
    val = val / (tot[n - 1] * tot[0]);
    val = 1.0 - val;
    ans += val;

    ans = ans * 2000;
    cout << fixed << setprecision(8) << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}