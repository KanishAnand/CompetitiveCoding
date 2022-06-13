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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

vector<lli> v, ans, dis;
vector<vector<pair<lli, lli>>> adj;

void findFirstparent(lli a, vector<lli> &parents) {
    lli beg = 0, end = sz(parents) - 1, node = -1;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli val = dis[a] - dis[parents[mid]];
        if (val > v[a]) {
            node = parents[mid];
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (node != -1) {
        ans[node] -= 1;
    }
}

lli dfs(lli a, vector<lli> &parents) {
    lli cnt = 0;
    parents.pb(a);
    for (auto val : adj[a]) {
        dis[val.first] = dis[a] + val.second;
        cnt += dfs(val.first, parents);
    }
    parents.pop_back();

    findFirstparent(a, parents);

    ans[a] += cnt;
    return ans[a] + 1;
}

void solve() {
    lli n, a, w;
    cin >> n;

    dis.resize(n + 2, 0);
    ans.resize(n + 2, 0);

    v.pb(0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    adj.resize(n + 2);
    for (lli i = 2; i <= n; i++) {
        cin >> a >> w;
        adj[a].pb({i, w});
    }

    vector<lli> parents;
    dfs(1, parents);

    for (lli i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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