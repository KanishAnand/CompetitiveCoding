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
    // lli x, y, l, r, mx = -1, ans;
    // cin >> x >> y >> l >> r;
    // for (lli i = l; i <= r; i++) {
    //     lli val = (i & x) * (i & y);
    //     if (val > mx) {
    //         mx = val;
    //         ans = i;
    //     }
    // }
    // cout << mx << endl;
    // cout << ans << endl;
    cout << bitset<32>(21508) << endl;
    cout << bitset<32>(21505) << endl;
    cout << bitset<32>(12177) << endl;
    cout << bitset<32>(21508) << endl;

    lli val1 = (12177 & 21508);
    lli val2 = (21508 & 12548);
    cout << val1 << " " << val2 << endl;
    val1 = (12177 & 21505);
    val2 = (21508 & 12545);
    cout << val1 << " " << val2 << endl;
    lli val = (12177 & 21508) * (21508 & 12548);
    cout << val << endl;
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