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
    lli n, a, m;
    cin >> n >> m;
    vector<vector<lli>> v(n + 2);
    lli flag = 0;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> a;
            if (a > 4) {
                flag = 1;
            }
            v[i].pb(a);
        }
    }

    if (flag == 1) {
        cout << "NO" << endln;
        return;
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                continue;
            }
            lli cnt = 0;
            if (i != 0 && v[i - 1][j] != 0) {
                cnt++;
            }
            if (i != n - 1 && v[i + 1][j] != 0) {
                cnt++;
            }
            if (j != 0 && v[i][j - 1] != 0) {
                cnt++;
            }
            if (j != m - 1 && v[i][j + 1] != 0) {
                cnt++;
            }
            if (cnt == v[i][j]) {
                continue;
            } else if (cnt > v[i][j]) {
                v[i][j] = cnt;
            } else {
                if (cnt < v[i][j] && i != 0 && v[i - 1][j] == 0) {
                    v[i - 1][j] = 1;
                    cnt++;
                }
                if (cnt < v[i][j] && i != n - 1 && v[i + 1][j] == 0) {
                    v[i + 1][j] = 1;
                    cnt++;
                }
                if (cnt < v[i][j] && j != 0 && v[i][j - 1] == 0) {
                    v[i][j - 1] = 1;
                    cnt++;
                }
                if (cnt < v[i][j] && j != m - 1 && v[i][j + 1] == 0) {
                    v[i][j + 1] = 1;
                    cnt++;
                }
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                continue;
            }
            lli cnt = 0;
            if (i != 0 && v[i - 1][j] != 0) {
                cnt++;
            }
            if (i != n - 1 && v[i + 1][j] != 0) {
                cnt++;
            }
            if (j != 0 && v[i][j - 1] != 0) {
                cnt++;
            }
            if (j != m - 1 && v[i][j + 1] != 0) {
                cnt++;
            }
            if (cnt == v[i][j]) {
                continue;
            } else if (cnt > v[i][j]) {
                v[i][j] = cnt;
            } else {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }

    if (flag == 1) {
        cout << "NO" << endln;
        return;
    }
    cout << "YES" << endln;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cout << v[i][j] << " ";
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