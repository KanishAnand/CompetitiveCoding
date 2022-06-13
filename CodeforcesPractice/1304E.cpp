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

// can be changed according to need
lli logn = 18;
// dp[i][j] is the '2^j'th parent of i
vector<vector<lli>> dp, adj;
vector<lli> vis, ht;

// storing 2^j th parent of i with dfs
void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dp[val][0] = a;
            for (lli j = 1; j <= logn; j++) {
                dp[val][j] = dp[dp[val][j - 1]][j - 1];
            }
            ht[val] = ht[a] + 1;
            dfs(val);
        }
    }
}

lli lca(lli a, lli b) {
    if (ht[a] < ht[b]) {
        swap(a, b);
    }

    if (ht[a] != ht[b]) {
        for (lli i = logn; i >= 0; i--) {
            if (dp[a][i] == 0) {
                continue;
            }
            lli val = dp[a][i];
            if (ht[val] >= ht[b]) {
                a = val;
            }
        }
    }

    if (a == b) {
        return a;
    }

    for (lli i = logn; i >= 0; i--) {
        if (dp[a][i] == 0 || dp[b][i] == 0) {
            continue;
        }
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

lli dist(lli a, lli b) {
    lli ancstr = lca(a, b);
    return ht[a] + ht[b] - 2 * ht[ancstr];
}

void solve() {
    lli n, a, b;
    cin >> n;

    dp.resize(n + 2, vector<lli>(logn + 2, 0));
    adj.resize(n + 2);
    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    ht.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);

    lli q, k, x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y >> a >> b >> k;
        lli val1 = dist(a, b);
        lli val2 = dist(a, x) + 1 + dist(b, y);
        lli val3 = dist(a, y) + 1 + dist(b, x);

        if (k % 2 == val1 % 2 && val1 <= k) {
            cout << "YES" << endl;
        } else if (k % 2 == val2 % 2 && val2 <= k) {
            cout << "YES" << endl;
        } else if (k % 2 == val3 % 2 && val3 <= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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