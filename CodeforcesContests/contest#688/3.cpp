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
    lli n, a;
    cin >> n;

    string st;
    vector<string> path;
    for (lli i = 0; i < n; i++) {
        cin >> st;
        path.pb(st);
    }

    vector<vector<lli>> row_left(n + 2, vector<lli>(12, -1)), row_right(n + 2, vector<lli>(12, -1));

    for (lli i = 0; i < n; i++) {
        for (lli dig = 0; dig <= 9; dig++) {
            for (lli j = 0; j < n; j++) {
                if (path[i][j] == (char)(dig + '0')) {
                    row_left[i][dig] = j;
                    break;
                }
            }
            for (lli j = n - 1; j >= 0; j--) {
                if (path[i][j] == (char)(dig + '0')) {
                    row_right[i][dig] = j;
                    break;
                }
            }
        }
    }

    vector<vector<lli>> col_up(n + 2, vector<lli>(12, -1)), col_down(n + 2, vector<lli>(12, -1));

    for (lli i = 0; i < n; i++) {
        for (lli dig = 0; dig <= 9; dig++) {
            for (lli j = 0; j < n; j++) {
                if (path[j][i] == (char)(dig + '0')) {
                    col_up[i][dig] = j;
                    break;
                }
            }
            for (lli j = n - 1; j >= 0; j--) {
                if (path[j][i] == (char)(dig + '0')) {
                    col_down[i][dig] = j;
                    break;
                }
            }
        }
    }

    vector<lli> row_up(12, -1), row_down(12, -1);

    for (lli dig = 0; dig <= 9; dig++) {
        for (lli i = 0; i < n; i++) {
            if (row_left[i][dig] != -1) {
                row_up[dig] = i;
                break;
            }
        }
        for (lli i = n - 1; i >= 0; i--) {
            if (row_left[i][dig] != -1) {
                row_down[dig] = i;
                break;
            }
        }
    }

    vector<lli> col_left(12, -1), col_right(12, -1);

    for (lli dig = 0; dig <= 9; dig++) {
        for (lli i = 0; i < n; i++) {
            if (col_up[i][dig] != -1) {
                col_left[dig] = i;
                break;
            }
        }
        for (lli i = n - 1; i >= 0; i--) {
            if (col_up[i][dig] != -1) {
                col_right[dig] = i;
                break;
            }
        }
    }

    vector<lli> ans(12, 0);

    for (lli dig = 0; dig <= 9; dig++) {
        for (lli i = 0; i < n; i++) {
            for (lli j = 0; j < n; j++) {
                if (path[i][j] == (char)(dig + '0')) {
                    lli p = row_left[i][dig];
                    lli q = row_right[i][dig];
                    if (p != -1 && q != -1) {
                        lli base = max(abs(j - p), abs(j - q));
                        lli ht = max(i, n - 1 - i);
                        lli val = base * ht;
                        ans[dig] = max(ans[dig], val);

                        base = max(j, n - 1 - j);
                        if (row_up[dig] != -1) {
                            ans[dig] = max({ans[dig], base * abs(i - row_up[dig]), base * abs(row_down[dig] - i)});
                        }
                    }

                    p = col_up[j][dig];
                    q = col_down[j][dig];

                    if (p != -1 && q != -1) {
                        lli base = max(abs(i - p), abs(i - q));
                        lli ht = max(j, n - 1 - j);
                        lli val = base * ht;
                        ans[dig] = max(ans[dig], val);

                        base = max(i, n - 1 - i);
                        if (col_left[dig] != -1) {
                            ans[dig] = max({ans[dig], base * abs(j - col_left[dig]), base * abs(col_right[dig] - j)});
                        }
                    }
                }
            }
        }
    }

    for (lli i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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