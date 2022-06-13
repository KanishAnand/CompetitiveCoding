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
vector<vector<lli>> adj;
vector<lli> vec, ans;

lli bfs(vector<lli> v) {
    queue<lli> qu;

    lli inf = 1e6;
    vector<lli> dist(n + 2, inf);

    for (lli i = 0; i < v.size(); i++) {
        qu.push(v[i]);
        dist[v[i]] = 0;
    }

    while (!qu.empty()) {
        lli a = qu.front();
        qu.pop();
        for (lli i = 0; i < adj[a].size(); i++) {
            lli val = adj[a][i];
            if (dist[val] > dist[a] + 1) {
                dist[val] = dist[a] + 1;
                qu.push(val);
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        if (dist[i] != inf && dist[i] != 0) {
            ans[i] = dist[i];
        }
    }
}

void solve() {
    lli a;
    cin >> n;
    vector<lli> even, odd;
    ans.resize(n + 2, -1);
    adj.resize(n + 2);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) {
            even.pb(i);
        } else {
            odd.pb(i);
        }
        lli left = i - a;
        lli right = i + a;
        if (left >= 0) {
            adj[left].pb(i);
        }
        if (right < n) {
            adj[right].pb(i);
        }
        vec.pb(a);
    }

    bfs(even);
    bfs(odd);

    for (lli i = 0; i < n; i++) {
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