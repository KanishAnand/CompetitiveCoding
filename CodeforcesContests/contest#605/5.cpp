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
vector<vector<lli>> adj;
lli n;
vector<lli> v, ans, vis;

lli dfs_even(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (v[val] % 2 == 1) {
            ans[a] = 1;
        } else {
            if (vis[val] == 0) {
                vis[val] = 1;
                lli p = 1 + dfs_even(val);
                if (p == 0) {
                    p = -1;
                }
                if (ans[a] == -1) {
                    ans[a] = p;
                } else {
                    if (p != -1) {
                        ans[a] = min(ans[a], p);
                    }
                }
            } else {
                if (ans[a] == -1) {
                    if (ans[val] == -1) {
                        ans[a] = -1;
                    } else {
                        ans[a] = ans[val] + 1;
                    }
                } else {
                    if (ans[val] != -1) {
                        ans[a] = min(ans[a], 1 + ans[val]);
                    }
                }
            }
        }
    }
    return ans[a];
}

lli dfs_odd(lli a) {
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (v[val] % 2 == 0) {
            ans[a] = 1;
        } else {
            if (vis[val] == 0) {
                vis[val] = 1;
                lli p = 1 + dfs_odd(val);
                if (p == 0) {
                    p = -1;
                }
                if (ans[a] == -1) {
                    ans[a] = p;
                } else {
                    if (p != -1) {
                        ans[a] = min(ans[a], p);
                    }
                }
            } else {
                if (ans[a] == -1) {
                    if (ans[val] == -1) {
                        ans[a] = -1;
                    } else {
                        ans[a] = ans[val] + 1;
                    }
                } else {
                    if (ans[val] != -1) {
                        ans[a] = min(ans[a], 1 + ans[val]);
                    }
                }
            }
        }
    }
    return ans[a];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a;
    cin >> n;
    v.pb(0);
    input(n, v);
    adj.resize(n + 2);
    for (lli i = 1; i <= n; i++) {
        a = v[i];
        if (i - a > 0) {
            adj[i].pb(i - a);
        }
        if (i + a <= n) {
            adj[i].pb(i + a);
        }
    }

    vis.resize(n + 2, 0);
    ans.resize(n + 2, -1);

    for (lli i = 1; i <= n; i++) {
        if (adj[i].size() == 0) {
            ans[i] = -1;
        } else if (vis[i] == 0 && v[i] % 2 == 0) {
            vis[i] = 1;
            dfs_even(i);
        }
    }

    for (lli i = 1; i <= n; i++) {
        if (adj[i].size() == 0) {
            ans[i] = -1;
        } else if (vis[i] == 0 && v[i] % 2 == 1) {
            vis[i] = 1;
            dfs_odd(i);
        }
    }

    for (lli i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
    rt;
}
