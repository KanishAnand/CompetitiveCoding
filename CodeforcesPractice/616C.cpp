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

lli n, m, beg = 1;
map<lli, lli> mp;
vector<string> v;

void dfs(lli i, lli j, vector<string> &v, vector<vector<lli>> &vis) {
    if (v[i][j] != '.' || vis[i][j] != 0) {
        return;
    }

    vis[i][j] = beg;
    mp[beg]++;
    mp[beg] %= 10;

    if (i != 0) {
        dfs(i - 1, j, v, vis);
    }
    if (i != n - 1) {
        dfs(i + 1, j, v, vis);
    }
    if (j != 0) {
        dfs(i, j - 1, v, vis);
    }
    if (j != m - 1) {
        dfs(i, j + 1, v, vis);
    }
}

void solve() {
    cin >> n >> m;
    string st;

    for (lli i = 0; i < n; i++) {
        cin >> st;
        v.pb(st);
    }

    vector<vector<lli>> vis(n + 2, vector<lli>(m + 2, 0));

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == '.') {
                dfs(i, j, v, vis);
                beg++;
            }
        }
    }

    st = "";
    for (lli i = 0; i < m; i++) {
        st += '.';
    }

    vector<string> ans(n + 2, st);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            if (v[i][j] == '*') {
                set<lli> st;
                if (i != 0) {
                    st.insert(vis[i - 1][j]);
                }
                if (i != n - 1) {
                    st.insert(vis[i + 1][j]);
                }
                if (j != 0) {
                    st.insert(vis[i][j - 1]);
                }
                if (j != m - 1) {
                    st.insert(vis[i][j + 1]);
                }
                lli val = 1;
                for (auto vv : st) {
                    val += mp[vv];
                    val %= 10;
                }
                ans[i][j] = (char)(val + '0');
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
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