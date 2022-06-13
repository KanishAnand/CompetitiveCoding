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

lli n, m, k, x;
vector<bool> vis;
vector<vector<lli>> adj, dp, dp2, dp3;

void dfs(lli a) {
    bool flag = 0;
    vector<lli> tmp1(x + 2, 0), tmp2(x + 2, 0), tmp3(x + 2, 0);

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            if (flag == 0) {
                tmp1 = dp1[val];
                tmp2 = dp2[val];
                tmp3 = dp3[val];
            } else {
                for (lli i = 0; i <= x; i++) {
                    for (lli j = 0; j <= x; j++) {
                        if (i + j > x) {
                            continue;
                        }
                        tmp1[i + j] = (tmp1[i] * dp[val][j]) % MOD;
                    }
                }
            }
            flag = 1;
        }
    }

    // leaves : Base state
    if (flag == 0) {
        // this is k
        dp[a][1] = 1;
        // this is non k
        dp2[a][0] = m - 1;
        // other k
        dp3[a][0] = k - 1;
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 2);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cin >> k >> x;
    dp.resize(n + 2, vector<lli>(x + 2, 0));
    dp2.resize(n + 2, vector<lli>(x + 2, 0));
    dp3.resize(n + 2, vector<lli>(x + 2, 0));
    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}