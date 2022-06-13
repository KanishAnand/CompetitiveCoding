#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
vector<lli> vis, col;
lli maxx = 1;
vector<vector<lli>> adj;
// lli x = 0, y = 0;

void dfs(lli a, lli x, lli y) {
    // if (vis[a] == 1) {
    //     return;
    // }s
    cout << a << x << y << endl;
    // x = y;
    // y = p;
    lli cnt = 1;
    fr(i, 0, adj[a].size()) {
        if (vis[adj[a][i]] == 0) {
            vis[adj[a][i]] = 1;
            // cout << x << " " << y << endl;
            while (cnt == x || cnt == y) {
                ++cnt;
            }
            col[adj[a][i]] = cnt;
            if (cnt > maxx) {
                maxx = cnt;
            }
            dfs(adj[a][i], y, col[adj[a][i]]);
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b;
    cin >> n;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    col.resize(n + 2, 0);
    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    col[1] = 1;
    // fr(i, 1, n + 1) {
    lli x, y;
    x = 0;
    y = col[1];
    // if (vis[i] == 0) {
    vis[1] = 1;
    dfs(1, x, y);
    // }
    // }
    cout << maxx << endl;
    fr(i, 1, n + 1) {
        cout << col[i] << " ";
    }
    cout << endl;
    rt;
}
