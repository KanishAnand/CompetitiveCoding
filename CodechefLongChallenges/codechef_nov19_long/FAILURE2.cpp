#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;
lli n;

lli bfs(lli a, lli b, vector<vector<lli>> &adj, queue<lli> &qu,
        vector<lli> &arr) {
    vector<lli> parent(n + 2, 0);
    while (!qu.empty()) {
        lli a = qu.front();
        qu.pop();
        for (lli i = 0; i < adj[a].size(); i++) {
            if (adj[a][i] == b) {
                continue;
            }
            if (arr[adj[a][i]] == 0) {
                parent[adj[a][i]] = a;
                qu.push(adj[a][i]);
                arr[adj[a][i]] = 1;
            } else {
                if (parent[a] != adj[a][i]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        lli m;
        cin >> n >> m;
        vector<lli> arr;
        arr.resize(n + 2, 0);
        vector<vector<lli>> adj;
        adj.resize(n + 2);
        lli a, b;
        fr(i, 0, m) {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        int fl = 0;
        for (lli j = 0; j <= n; j++) {
            fl = 0;
            for (lli i = 0; i <= n; i++) {
                arr[i] = 0;
            }
            queue<lli> qu;
            int p = 0;
            for (lli i = 1; i <= n; i++) {
                if (i != j) {
                    if (arr[i] == 0) {
                        qu.push(i);
                        arr[i] = 1;
                        p = bfs(i, j, adj, qu, arr);
                        if (p == 1) {
                            break;
                        }
                    }
                }
            }
            if (p == 0) {
                if (j == 0) {
                    cout << "-1" << endl;
                    fl = 1;
                    break;
                } else {
                    fl = 1;
                    cout << j << endl;
                    break;
                }
            }
            if (fl == 1) {
                break;
            }
        }

        if (fl == 0) {
            cout << "-1" << endl;
        }
    }

    rt;
}
