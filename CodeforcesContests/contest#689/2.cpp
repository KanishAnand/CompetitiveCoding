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
    lli n, m;
    cin >> n >> m;
    string st;
    vector<string> mat;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        mat.pb(st);
    }

    vector<vector<lli>> left(n + 2, vector<lli>(m + 2, 0));

    for (lli i = 0; i < n; i++) {
        lli cnt = 0;
        for (lli j = 0; j < m; j++) {
            left[i][j] = cnt;
            if (mat[i][j] == '*') {
                cnt++;
            } else {
                cnt = 0;
            }
        }
    }

    vector<vector<lli>> right(n + 2, vector<lli>(m + 2, 0));

    for (lli i = 0; i < n; i++) {
        lli cnt = 0;
        for (lli j = m - 1; j >= 0; j--) {
            right[i][j] = cnt;
            if (mat[i][j] == '*') {
                cnt++;
            } else {
                cnt = 0;
            }
        }
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (mat[i][j] == '.') {
                continue;
            }
            lli val = 0, no = 1;
            for (lli k = i + 1; k < n; k++) {
                if (mat[k][j] == '.') {
                    break;
                }
                val += 1;
                if (left[k][j] >= val && right[k][j] >= val) {
                    no++;
                    continue;
                } else {
                    val -= 1;
                    break;
                }
            }

            ans += no;
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