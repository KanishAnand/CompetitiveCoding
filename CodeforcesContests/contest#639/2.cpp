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
vector<lli> pyr(26006, 0);

void solve() {
    lli n, a, cnt = 0;
    cin >> n;
    for (lli i = 25821; i >= 1; i--) {
        if (n >= pyr[i]) {
            lli val = n / pyr[i];
            n -= pyr[i] * val;
            cnt += val;
        }
    }
    cout << cnt << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    pyr[1] = 2;

    for (lli i = 2; i < 26000; i++) {
        pyr[i] = pyr[i - 1] + 3 * i - 1;
    }

    while (t--)
        solve();
    rt;
}