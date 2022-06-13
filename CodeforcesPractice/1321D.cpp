#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

lli n;
vector<vector<lli>> adj, trans;
vector<lli> dis;

lli bfs(lli root, vector<lli> &visit) {
    queue<lli> qu;
    qu.push(root);

    while (!qu.empty()) {
        lli a = qu.front();
        qu.pop();
        for (lli i = 0; i < trans[a].size(); i++) {
            if (visit[trans[a][i]] == 0) {
                qu.push(trans[a][i]);
                dis[trans[a][i]] = dis[a] + 1;
                visit[trans[a][i]] = 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, m, b, k;
    cin >> n >> m;
    dis.resize(n + 2, 0);
    vector<lli> v;
    adj.resize(n + 2);
    trans.resize(n + 2);

    fr(i, 0, m) {
        cin >> a >> b;
        adj[a].pb(b);
        trans[b].pb(a);
    }

    cin >> k;
    fr(i, 0, k) {
        cin >> a;
        v.pb(a);
    }
    vector<lli> visit(n + 2, 0);
    visit[a] = 1;
    bfs(a, visit);
    lli mn = 0, mx = 0;

    for (lli i = 0; i < v.size() - 1; i++) {
        a = 0;
        b = 0;
        for (lli j = 0; j < adj[v[i]].size(); j++) {
            if (dis[adj[v[i]][j]] == dis[v[i]] - 1) {
                a++;
            } else {
                b++;
            }
        }
        if (dis[v[i + 1]] == dis[v[i]] - 1 && a != 1) {
            mx++;
        } else if (dis[v[i + 1]] != dis[v[i]] - 1) {
            mn++;
            mx++;
        }
    }

    cout << mn << " " << mx << endl;
    rt;
}