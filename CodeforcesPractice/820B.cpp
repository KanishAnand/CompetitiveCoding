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
    double n, a;
    cin >> n >> a;
    double val = n / 2, q, v2;
    double mn = 1e3;

    for (lli i = 2; i <= val + 1; i++) {
        double p = (180 * (i - 1)) / n;
        double p2 = 180 - p;
        p = fabs(p - a);
        p2 = fabs(p2 - a);
        if (p < mn) {
            mn = p;
            q = i;
            v2 = n;
        }
        if (p2 < mn && i != 2) {
            mn = p2;
            q = i;
            v2 = 2;
        }
    }

    cout << "1 " << v2 << " " << q << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}