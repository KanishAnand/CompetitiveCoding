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

vector<lli> vis;
vector<vector<lli>> adj;
stack<lli> topo;
bool cycle = 0;

void dfs(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            vis[val] = 2;
            topo.push(val);
        } else if (vis[val] == 1) {
            cycle = 1;
            return;
        }
    }
}

void solve() {
    lli n, a, b;
    cin >> n;
    vis.resize(n + 2, 0);
    adj.resize(n + 2);

    for (lli i = 1; i <= n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 2;
            topo.push(i);
        }
    }

    if (cycle == 1) {
        cout << "-1" << endln;
    } else {
        cout << topo.size() << endl;
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