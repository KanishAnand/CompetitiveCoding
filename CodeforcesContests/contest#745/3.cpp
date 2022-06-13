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
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<string> grid;
vector<vector<int>> pref, prefCol;

void solve() {
    grid.clear();
    pref.clear();
    prefCol.clear();

    int n, m;
    cin >> n >> m;

    string st;
    pref.resize(n, vector<int>(m, 0));
    prefCol.resize(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cin >> st;
        grid.pb(st);
        for (int j = 0; j < m; j++) {
            if (j) {
                pref[i][j] = pref[i][j - 1];
            }
            if (st[j] == '1') {
                pref[i][j]++;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (i) {
                prefCol[j][i] = prefCol[j][i - 1];
            }
            if (grid[i][j] == '0') {
                prefCol[j][i]++;
            }
        }
    }

    int ans = n * m;
    for (int start = 0; start < m; start++) {
        for (int end = start + 3; end < m; end++) {
            int colLen = end - start + 1;
            int insideOnes = 0;
            vector<int> rows;

            for (int i = 0; i <= 3; i++) {
                insideOnes += pref[i][end - 1] - pref[i][start];
            }

            for (int endRow = 4; endRow < n; endRow++) {
                int cnt = pref[endRow][end - 1] - pref[endRow][start];

                // for this
                int zerosHere = colLen - 2 - cnt;
                int colZeros =
                    prefCol[start][endRow - 1] + prefCol[end][endRow - 1];

                int tot = insideOnes + colZeros + zerosHere;
                rows.pb(tot);

                // for next iteration
                insideOnes += cnt;
            }

            vector<int> mn(n - 4);
            for (int i = n - 5; i >= 0; i--) {
                mn[i] = rows[i];
                if (i != n - 5) {
                    mn[i] = min(mn[i], mn[i + 1]);
                }
            }

            int outsideCnt = 0;
            for (int startRow = 0; startRow < n - 4; startRow++) {
                int cnt = pref[startRow][end - 1] - pref[startRow][start];
                outsideCnt += cnt;

                int colZeros =
                    prefCol[start][startRow] + prefCol[end][startRow];

                int sub = colZeros + outsideCnt;
                int zerosHere = (colLen - 2 - cnt);
                int tot = mn[startRow] + zerosHere - sub;

                ans = min(ans, tot);
            }
        }
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    rt;
}