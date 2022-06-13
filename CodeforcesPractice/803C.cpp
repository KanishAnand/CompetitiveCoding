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
    lli n, ans = -1, k;
    cin >> n >> k;

    if (k >= 1e6) {
        cout << "-1" << endl;
        return;
    }

    for (lli i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            lli val = (k * (k + 1)) / 2;
            val *= i;
            if (val <= n && (n - val) % i == 0) {
                ans = max(ans, i);
            }

            lli no = n / i;
            val = (k * (k + 1)) / 2;
            val *= no;
            if (val <= n && (n - val) % no == 0) {
                ans = max(ans, no);
            }
        }
    }

    if (ans == -1) {
        cout << ans << endl;
        return;
    }

    for (lli i = 1; i < k; i++) {
        lli p = i * ans;
        n -= p;
        cout << p << " ";
    }
    cout << n << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}