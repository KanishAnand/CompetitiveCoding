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
    lli n, a;
    cin >> n;

    if (n <= 4) {
        lli ans = (n * (n - 1)) / 2;
        cout << ans << endl;
        return;
    }

    lli cnt, val = 5, p = 1;

    while (1) {
        if (val <= n) {
            cnt = p;
        } else {
            break;
        }
        val *= 10;
        p++;
    }

    lli no = 0;
    p = 9;
    for (lli i = 1; i <= cnt; i++) {
        no += p;
        p *= 10;
    }

    p /= 9;
    lli ans = 0;

    for (lli i = 0; i <= 8; i++) {
        lli val = no + p * i;
        lli mid = val / 2;
        lli no1 = mid, no2 = mid + 1;
        if (no1 >= 1 && no2 <= n) {
            lli p1 = no1 - 1 + 1;
            lli p2 = n - no2 + 1;
            ans += min(p1, p2);
        }
    }

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