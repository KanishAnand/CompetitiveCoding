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
    lli n, a, m;
    cin >> n >> m;
    vector<string> st;
    string ss;

    for (lli i = 0; i < n; i++) {
        cin >> ss;
        st.pb(ss);
    }

    vector<vector<lli>> horizontalleft(n + 2, vector<lli>(m + 2, 0)),
        verticalup(n + 2, vector<lli>(m + 2, 0));
    vector<vector<lli>> horizontalright(n + 2, vector<lli>(m + 2, 0)),
        verticaldown(n + 2, vector<lli>(m + 2, 0));

    for (lli i = 0; i < n; i++) {
        horizontalleft[i][0] = 0;
        for (lli j = 1; j < m; j++) {
            if (st[i][j - 1] == '*' && st[i][j] == '*') {
                horizontalleft[i][j] = horizontalleft[i][j - 1] + 1;
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        horizontalright[i][m - 1] = 0;
        for (lli j = m - 2; j >= 0; j--) {
            if (st[i][j + 1] == '*' && st[i][j] == '*') {
                horizontalright[i][j] = horizontalright[i][j + 1] + 1;
            }
        }
    }

    for (lli i = 0; i < m; i++) {
        verticalup[0][i] = 0;
        for (lli j = 1; j < n; j++) {
            if (st[j][i] == '*' && st[j - 1][i] == '*')
                verticalup[j][i] = verticalup[j - 1][i] + 1;
        }
    }

    for (lli i = 0; i < m; i++) {
        verticaldown[n - 1][i] = 0;
        for (lli j = n - 2; j >= 0; j--) {
            if (st[j][i] == '*' && st[j + 1][i] == '*')
                verticaldown[j][i] = verticaldown[j + 1][i] + 1;
        }
    }

    vector<pair<pair<lli, lli>, lli>> ans;
    vector<vector<lli>> calch(n + 2, vector<lli>(m + 2, 0));
    vector<vector<lli>> calcv(n + 2, vector<lli>(m + 2, 0));

    for (lli i = 1; i < n - 1; i++) {
        for (lli j = 1; j < m - 1; j++) {
            if (st[i][j] != '*') {
                continue;
            }

            lli val = min({horizontalleft[i][j], horizontalright[i][j],
                           verticaldown[i][j], verticalup[i][j]});
            if (val != 0) {
                ans.pb({{i, j}, val});
                calcv[i - val][j]++;
                calcv[i + val + 1][j]--;
                calch[i][j - val]++;
                calch[i][j + val + 1]--;
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 1; j < m; j++) {
            calch[i][j] += calch[i][j - 1];
        }
    }

    for (lli i = 0; i < m; i++) {
        for (lli j = 1; j < n; j++) {
            calcv[j][i] += calcv[j - 1][i];
        }
    }

    lli flag = 0;
    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (st[i][j] == '*' && calch[i][j] <= 0 && calcv[i][j] <= 0) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        cout << "-1" << endl;
    } else {
        cout << ans.size() << endln;
        for (lli i = 0; i < ans.size(); i++) {
            cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1
                 << " " << ans[i].second << endln;
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