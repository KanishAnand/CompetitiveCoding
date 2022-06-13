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
    lli n, a, k;
    cin >> n >> k;
    lli ans = 0;
    if (k % n != 0) {
        ans = 2;
    }

    cout << ans << endln;
    lli val = k / n;
    lli mod = k % n;

    vector<vector<lli>> arr(n + 2, vector<lli>(n + 2, 0));

    lli beg = 0;
    for (lli i = 0; i < n; i++) {
        lli cnt = 0, j;
        for (j = beg;; j++) {
            if (cnt == val) {
                break;
            }
            arr[i][(j % n)] = 1;
            cnt++;
        }

        if (mod != 0) {
            arr[i][j % n] = 1;
            mod--;
        }
        beg++;
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << endln;
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