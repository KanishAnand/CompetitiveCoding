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
    lli la, ra, ta;
    lli lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    if (la < lb) {
        swap(la, lb);
        swap(ra, rb);
        swap(ta, tb);
    }

    lli gcd = __gcd(ta, tb);
    lli no = (la - lb) / gcd;
    lli val1 = lb - la + no * gcd;
    lli val2 = lb - la + (no + 1) * gcd;

    lli ans1, ans2;

    lli da = ra - la + 1;
    lli db = rb - lb + 1;

    if (val1 < 0) {
        ans1 = min(da, db + val1);
    } else {
        ans1 = min(da - val1, db);
    }

    if (val2 < 0) {
        ans2 = min(da, db + val2);
    } else {
        ans2 = min(da - val2, db);
    }

    cout << max({0ll, ans1, ans2}) << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}