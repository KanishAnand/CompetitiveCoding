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
int v[][4] = {{1, 2, 4, 7}, {3, 5, 8, 12}, {6, 9, 13, 18}, {10, 14, 19, 25}};

void solve() {
    lli n, a, m, b;
    n = 4;
    m = 4;
    cin >> a >> b;
    vector<vector<set<lli>>> store(n + 2, vector<set<lli>>(m + 2));
    store[0][0].insert(v[0][0]);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            lli val = v[i][j];
            if (i != 0) {
                for (auto it = store[i - 1][j].begin();
                     it != store[i - 1][j].end(); it++) {
                    store[i][j].insert(val + *it);
                }
            }
            if (j != 0) {
                for (auto it = store[i][j - 1].begin();
                     it != store[i][j - 1].end(); it++) {
                    store[i][j].insert(val + *it);
                }
            }
        }
    }

    cout << store[a][b].size() << endl;
}
void solve() {
    lli x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lli n = x2 - x1 + 1;
    lli m = y2 - y1 + 1;
    lli inc = n - 1;
    lli ans = (m - 1) * inc;
    ans++;
    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}