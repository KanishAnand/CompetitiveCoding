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
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    vector<lli> v, vis, ans;
    vector<vector<lli>> adj;
    cin >> n;
    adj.resize(n + 2);
    v.pb(0);
    input(n, v);

    for (lli i = 1; i <= n; i++) {
        a = v[i];
        if (i - a > 0) {
            adj[i - a].pb(i);
        }
        if (i + a <= n) {
            adj[i + a].pb(i);
        }
    }

    vis.resize(n + 2, 0);
    ans.resize(n + 2, -1);

    fr(i, 0, n) {
        if (v[i] % 2 == 0 && vis[v[i]] == 0) {
            vis[v[i]] = 1;
            queue<lli> qu;
            qu.push(v[i]);
            while (!qu.empty()) {
                lli f = qu.front();
                fr(j, 0, adj[f].size()) {
                    lli p = adj[f][j];
                    if (v[p] % 2 == 1) {
                        if (v[f] % 2 == 0) {
                            ans[p] = 1;
                        } else {
                            ans[p] = ans[f] + 1;
                        }
                        should use min  /////////////
                    }
                    qu.push(p);
                }
            }
        }
    }
