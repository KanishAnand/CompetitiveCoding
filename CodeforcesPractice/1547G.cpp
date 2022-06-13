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

lli inf = 0, fin = 0;
vector<lli> vis, mark;
vector<vector<lli>> adj;

void dfsMark(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfsMark(val);
        } else if (vis[val] == 1) {
            mark[val] = -1;
        } else if (mark[val] != -1) {
            mark[val] = 2;
        }
    }

    vis[a] = 2;
}

void dfs(lli a) {
    if (mark[a] == -1) {
        inf++;
    }
    if (mark[a] == 2) {
        fin++;
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0 || (inf > 0 && mark[val] != -1)) {
            vis[val] = 1;
            if (inf > 0) {
                mark[val] = -1;
            } else if (fin > 0 && mark[val] != -1) {
                mark[val] = 2;
            }

            dfs(val);
        }
    }

    if (mark[a] == -1) {
        inf--;
    }
    if (mark[a] == 2) {
        fin--;
    }
}

void solve() {
    adj.clear();
    vis.clear();
    mark.clear();

    lli n, m, a, b;
    cin >> n >> m;

    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }

    vis.resize(n + 2, 0);
    mark.resize(n + 2, 0);
    vis[1] = 1;
    dfsMark(1);

    for (lli i = 1; i <= n; i++) {
        if (vis[i] != 0 && mark[i] == 0) {
            mark[i] = 1;
        }
    }

    vis.clear();
    vis.resize(n + 2, 0);
    vis[1] = 1;
    inf = 0;
    fin = 0;
    dfs(1);

    for (lli i = 1; i <= n; i++) {
        cout << mark[i] << " ";
    }
    cout << endln;
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