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

void solve() {
    lli n, m, k, a, b, c;
    cin >> n >> m >> k;

    vector<vector<lli>> adj(n + 2);
    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    map<pair<pair<lli, lli>, lli>, lli> forb;
    for (lli i = 0; i < k; i++) {
        cin >> a >> b >> c;
        forb[{{a, b}, c}] = 1;
    }

    queue<pair<lli, pair<lli, lli>>> qu;
    qu.push({0, {-1, 1}});

    lli ans = -1;
    vector<vector<lli>> vis(n + 2, vector<lli>(n + 2, 0)), dist(n + 2, vector<lli>(n + 2, -1));

    while (!qu.empty()) {
        pair<lli, pair<lli, lli>> pr = qu.front();
        lli dis = pr.first, grandfather = pr.second.first, father = pr.second.second;
        qu.pop();
        for (auto val : adj[father]) {
            if (vis[father][val] != 1 && forb[{{grandfather, father}, val}] == 0) {
                vis[father][val] = 1;
                dist[father][val] = dis + 1;
                if (val == n) {
                    if (ans == -1) {
                        ans = dis + 1;
                    }
                    ans = min(ans, dis + 1);
                }
                qu.push({dis + 1, {father, val}});
            }
        }
    }

    cout << ans << endl;
    if (ans == -1) {
        return;
    }

    lli no = n;
    vector<lli> v;
    v.pb(n);
    while (ans > 0) {
        for (lli i = 1; i <= n; i++) {
            if (dist[i][no] == ans) {
                no = i;
                v.pb(no);
                ans--;
                break;
            }
        }
    }

    for (lli i = sz(v) - 1; i >= 0; i--) {
        cout << v[i] << " ";
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