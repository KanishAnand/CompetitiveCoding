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
    lli n, a, m;
    cin >> n >> m;
    vector<lli> rows, cols;
    lli r = 0, c = 0;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        r ^= a;
        rows.pb(a);
    }

    for (lli i = 0; i < m; i++) {
        cin >> a;
        c ^= a;
        cols.pb(a);
    }

    if (c != r) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        lli val = 0;
        for (lli i = 1; i < m; i++) {
            val ^= cols[i];
        }
        val ^= rows[0];

        cout << val << " ";
        for (lli i = 1; i < m; i++) {
            cout << cols[i] << " ";
        }
        cout << endl;
        for (lli i = 1; i < n; i++) {
            cout << rows[i] << " ";
            for (lli j = 1; j < m; j++) {
                cout << "0 ";
            }
            cout << endl;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}