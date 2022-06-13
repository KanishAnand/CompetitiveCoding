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

lli INF = -1e9;
vector<lli> marked, vis, Downdist, UpDist;
vector<vector<lli>> adj;

void Downdfs(lli a) {
    lli mx = INF;
    if (marked[a]) {
        mx = 0;
    }
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            Downdfs(val);
            mx = max(mx, Downdist[val] + 1);
        }
    }

    Downdist[a] = mx;
}

void Updfs(lli a) {
    lli mx1 = INF, mx2 = INF;
    vector<lli> tmp;
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            tmp.pb(Downdist[val] + 1);
        }
    }

    sort(tmp.rbegin(), tmp.rend());
    if (sz(tmp) > 0) {
        mx1 = tmp[0];
    }
    if (sz(tmp) > 1) {
        mx2 = tmp[1];
    }

    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            lli mx = mx1;
            if (Downdist[val] + 1 == mx1) {
                mx = mx2;
            }
            UpDist[val] = max(UpDist[a] + 1, mx + 1);
            if (marked[a]) {
                UpDist[val] = max(UpDist[val], 1ll);
            }
            Updfs(val);
        }
    }
}

void solve() {
    lli n, a, m, d, b;
    cin >> n >> m >> d;

    marked.resize(n + 2, 0);
    for (lli i = 0; i < m; i++) {
        cin >> a;
        marked[a] = 1;
    }

    adj.resize(n + 2);
    for (lli i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    Downdist.resize(n + 2, INF);
    vis[1] = 1;
    Downdfs(1);

    vis.clear();
    vis.resize(n + 2, 0);
    UpDist.resize(n + 2, INF);
    vis[1] = 1;
    Updfs(1);

    lli ans = 0;
    for (lli i = 1; i <= n; i++) {
        // cout << i << " " << UpDist[i] << " " << Downdist[i] << endl;
        if (max(UpDist[i], Downdist[i]) <= d) {
            ans++;
        }
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