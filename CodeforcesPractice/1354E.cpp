#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;

vector<vector<lli>> adj;
vector<lli> vis;

void dfs(lli a, vector<lli> &coll, vector<vector<lli>> &v, lli col) {
    v[col].pb(a);
    coll[a] = col;
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val, coll, v, 1 - col);
        } else {
            if (coll[val] == col) {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
}

void solve() {
    lli n, a, m, n1, n2, n3, b;
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<pair<vector<lli>, vector<lli>>> store;

    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            vector<vector<lli>> v(2);
            vector<lli> coll(n + 2, 0);
            dfs(i, coll, v, 0);
            store.pb({v[0], v[1]});
        }
    }

    lli cnt = sz(store);

    vector<vector<lli>> dp(cnt + 2, vector<lli>(5002, 0));
    if (sz(store[0].first) <= n2) {
        dp[0][sz(store[0].first)] = 1;
    }
    if (sz(store[0].second) <= n2) {
        dp[0][sz(store[0].second)] = 1;
    }

    for (lli i = 1; i < cnt; i++) {
        a = sz(store[i].first);
        b = sz(store[i].second);
        for (lli j = 0; j <= n2; j++) {
            if (j + a <= n2) {
                if (dp[i - 1][j] == 1) {
                    dp[i][j + a] = 1;
                }
            }
            if (j + b <= n2) {
                if (dp[i - 1][j] == 1) {
                    dp[i][j + b] = 1;
                }
            }
        }
    }

    if (dp[cnt - 1][n2] == 0) {
        cout << "NO" << endl;
        return;
    }

    lli val = cnt - 1, no = n2;
    vector<lli> ans;

    while (1) {
        lli no1 = sz(store[val].first);
        lli no2 = sz(store[val].second);
        if (val == 0) {
            if (no1 == no) {
                ans.pb(0);
            } else if (no2 == no) {
                ans.pb(1);
            }
            break;
        }

        if (no1 <= no && dp[val - 1][no - no1] != 0) {
            ans.pb(0);
            no -= no1;
            val--;
        } else if (no2 <= no && dp[val - 1][no - no2] != 0) {
            ans.pb(1);
            no -= no2;
            val--;
        }
    }

    val = cnt - 1;
    vector<lli> colr(n + 2, 0);

    for (lli i = 0; i < ans.size(); i++) {
        if (ans[i] == 0) {
            for (auto vv : store[val].first) {
                colr[vv] = 2;
            }
        } else {
            for (auto vv : store[val].second) {
                colr[vv] = 2;
            }
        }
        val--;
    }

    for (lli i = 1; i <= n; i++) {
        if (colr[i] == 0) {
            if (n1 != 0) {
                colr[i] = 1;
                n1--;
            } else if (n3 != 0) {
                colr[i] = 3;
                n3--;
            }
        }
    }

    cout << "YES" << endl;
    for (lli i = 1; i <= n; i++) {
        cout << colr[i];
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}