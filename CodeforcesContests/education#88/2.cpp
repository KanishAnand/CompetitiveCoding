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
    lli n, a, m, x, y;
    cin >> n >> m >> x >> y;
    vector<string> store;
    string st;

    for (lli i = 0; i < n; i++) {
        cin >> st;
        store.pb(st);
    }

    if (x * 2 <= y) {
        lli cnt = 0;
        for (lli i = 0; i < n; i++) {
            for (lli j = 0; j < m; j++) {
                if (store[i][j] == '.') {
                    cnt++;
                }
            }
        }
        lli ans = cnt * x;
        cout << ans << endln;
    } else {
        lli ones = 0, twos = 0;
        for (lli i = 0; i < n; i++) {
            for (lli j = 0; j < m; j++) {
                if (store[i][j] == '.') {
                    if (j != m - 1 && store[i][j + 1] == '.') {
                        twos++;
                        j++;
                    } else {
                        ones++;
                    }
                }
            }
        }

        lli ans = (ones * x) + (twos * y);
        cout << ans << endln;
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