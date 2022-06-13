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
    lli n, k;
    string st;
    cin >> n >> k;
    vector<string> v;

    for (lli i = 0; i < n; i++) {
        cin >> st;
        v.pb(st);
    }

    lli mx = -1;
    vector<vector<lli>> dp(n + 2, vector<lli>(n + 2, 0));

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            } else if (i - 1 >= 0) {
                dp[i][j] = dp[i - 1][j];
            } else if (j - 1 >= 0) {
                dp[i][j] = dp[i][j - 1];
            }
            if (v[i][j] != 'a') {
                dp[i][j]++;
            }

            if (dp[i][j] <= k) {
                mx = max(mx, i + j);
            }
        }
    }

    set<pair<char, pair<lli, lli>>> start;

    if (mx == -1) {
        start.insert({v[0][0], {0, 0}});
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            if (dp[i][j] <= k && i + j == mx) {
                if (i + 1 < n) {
                    start.insert({v[i + 1][j], {i + 1, j}});
                }
                if (j + 1 < n) {
                    start.insert({v[i][j + 1], {i, j + 1}});
                }
            }
        }
    }

    string ans = "";
    for (lli i = 0; i <= mx; i++) {
        ans += 'a';
    }

    while (!start.empty()) {
        set<pair<char, pair<lli, lli>>> tmp;
        auto it = start.begin();
        char ch = (*it).first;
        ans += ch;
        for (auto val : start) {
            if (val.first == ch) {
                lli i = val.second.first, j = val.second.second;
                if (i + 1 < n) {
                    tmp.insert({v[i + 1][j], {i + 1, j}});
                }
                if (j + 1 < n) {
                    tmp.insert({v[i][j + 1], {i, j + 1}});
                }
            } else {
                break;
            }
        }

        start = tmp;
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}