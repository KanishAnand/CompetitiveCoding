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
    lli n, a;
    cin >> n;
    vector<string> st;
    string ss;
    for (lli i = 0; i < n; i++) {
        cin >> ss;
        st.pb(ss);
    }

    vector<vector<lli>> horizontalright(n + 2, vector<lli>(n + 2, 0)),
        verticaldown(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 0; i < n; i++) {
        horizontalright[i][n - 1] = 0;
        for (lli j = n - 2; j >= 0; j--) {
            if (st[i][j + 1] == '0') {
                horizontalright[i][j] = horizontalright[i][j + 1] + 1;
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        verticaldown[n - 1][i] = 0;
        for (lli j = n - 2; j >= 0; j--) {
            if (st[j + 1][i] == '0')
                verticaldown[j][i] = verticaldown[j + 1][i] + 1;
        }
    }

    lli flag = 0;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            if (st[i][j] == '1') {
                lli val1 = horizontalright[i][j];
                lli val2 = verticaldown[i][j];
                if (val1 != 0 && val2 != 0) {
                    flag = 1;
                    break;
                }
            }
        }
    }

    if (flag == 1) {
        cout << "NO" << endln;
    } else {
        cout << "YES" << endln;
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