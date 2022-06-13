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

lli x, y, a, b;

bool check(lli sum) {
    lli mnp, mxp;
    mxp = floor((double)(x - b * sum) / (double)(a - b));
    mnp = ceil((double)(y - a * sum) / (double)(b - a));
    mnp = max(mnp, 0ll);

    if (mxp < mnp) {
        return false;
    }

    lli mxq = sum - mnp;
    if (mxq >= 0) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    cin >> x >> y >> a >> b;

    if (a == b) {
        lli ans = min(x / a, y / a);
        cout << ans << endl;
        return;
    }

    if (a < b) {
        swap(a, b);
    }

    lli beg = 0, end = (x + y) / (a + b), ans = 0;
    while (beg <= end) {
        lli mid = (beg + end) / 2;
        if (check(mid)) {
            ans = mid;
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans << endl;
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