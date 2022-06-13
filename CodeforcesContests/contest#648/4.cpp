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

lli n, m;

void dfs(lli a, lli b, vector<vector<lli>> &vis, vector<string> &v) {
    if (vis[a][b] != 0) {
        return;
    }

    vis[a][b] = 1;

    if (a != 0 && v[a - 1][b] != '#') {
        dfs(a - 1, b, vis, v);
    }
    if (a != n - 1 && v[a + 1][b] != '#') {
        dfs(a + 1, b, vis, v);
    }
    if (b != 0 && v[a][b - 1] != '#') {
        dfs(a, b - 1, vis, v);
    }
    if (b != m - 1 && v[a][b + 1] != '#') {
        dfs(a, b + 1, vis, v);
    }
}

void solve() {
    lli a;
    cin >> n >> m;

    vector<string> v;
    string st;

    for (lli i = 0; i < n; i++) {
        cin >> st;
        v.pb(st);
    }

    lli cnt = 0;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == 'G') {
                cnt++;
            }
        }
    }

    if (cnt == 0) {
        cout << "YES" << endln;
        return;
    }

    lli flag = 0;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == 'B') {
                if (i != 0) {
                    if (v[i - 1][j] == 'G') {
                        flag = 1;
                        break;
                    }
                    if (v[i - 1][j] == '.') {
                        v[i - 1][j] = '#';
                    }
                }
                if (i != n - 1) {
                    if (v[i + 1][j] == 'G') {
                        flag = 1;
                        break;
                    }
                    if (v[i + 1][j] == '.') {
                        v[i + 1][j] = '#';
                    }
                }
                if (j != 0) {
                    if (v[i][j - 1] == 'G') {
                        flag = 1;
                        break;
                    }
                    if (v[i][j - 1] == '.') {
                        v[i][j - 1] = '#';
                    }
                }
                if (j != m - 1) {
                    if (v[i][j + 1] == 'G') {
                        flag = 1;
                        break;
                    }
                    if (v[i][j + 1] == '.') {
                        v[i][j + 1] = '#';
                    }
                }
            }
        }
        if (flag == 1) {
            cout << "NO" << endln;
            return;
        }
    }

    if (v[n - 1][m - 1] == '#') {
        cout << "NO" << endln;
        return;
    }

    lli ans = 1;
    vector<vector<lli>> vis(n + 2, vector<lli>(m + 2, 0));
    dfs(n - 1, m - 1, vis, v);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == 'G') {
                if (vis[i][j] != 1) {
                    ans = 0;
                    break;
                }
            }
        }
        if (ans == 0) {
            break;
        }
    }

    if (ans == 1) {
        cout << "YES" << endln;
    } else {
        cout << "NO" << endln;
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