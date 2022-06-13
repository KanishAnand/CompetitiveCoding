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

lli n;
vector<lli> vis, subtree;
vector<vector<lli>> adj;
vector<lli> centroid;

void dfs(lli a) {
    lli flag = 1;
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subtree[a] += subtree[val];
            if (subtree[val] > n / 2) {
                flag = 0;
            }
        }
    }

    subtree[a]++;

    if (n - subtree[a] > n / 2) {
        flag = 0;
    }

    if (flag == 1) {
        centroid.pb(a);
    }
}

void solve() {
    lli a, b;
    cin >> n;

    adj.clear();
    vis.clear();
    centroid.clear();
    subtree.clear();

    adj.resize(n + 2);
    subtree.resize(n + 2, 0);
    vis.resize(n + 2, 0);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis[1] = 1;
    dfs(1);

    if (centroid.size() == 1) {
        cout << "1 " << adj[1][0] << endl;
        cout << "1 " << adj[1][0] << endl;
        return;
    }

    a = centroid[0];
    b = centroid[1];

    lli c = adj[a][0];
    if (c == b) {
        c = adj[a][1];
    }

    cout << a << " " << c << endl;
    cout << b << " " << c << endl;
    return;
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