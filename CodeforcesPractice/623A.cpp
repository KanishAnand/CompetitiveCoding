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
    lli n, a, m, b;
    vector<lli> vis, v;
    vector<vector<lli>> adj;
    cin >> n >> m;
    vis.resize(n + 2, 0);
    adj.resize(n + 2);

    fr(i, 0, m) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    fr(i, 1, n + 1) {
        if (adj[i].size() != n - 1) {
            v.pb(i);
        } else {
            vis[i] = 1;
        }
    }
    // fr(i, 1, n + 1) {
    //     cout << vis[i] << " ";
    // }
    // cout << endl;

    if (v.size() == 0) {
        cout << "YES" << endl;
        fr(i, 0, n) {
            cout << "b";
        }
        cout << endl;
    } else {
        vis[v[0]] = 2;
        fr(i, 0, adj[v[0]].size()) {
            if (vis[adj[v[0]][i]] == 0) {
                vis[adj[v[0]][i]] = 2;
            }
        }
        lli in = -1;
        fr(i, 0, v.size()) {
            if (vis[v[i]] == 0) {
                vis[v[i]] = 3;
                in = i;
                break;
            }
        }
        lli flag = 0;
        if (in != -1) {
            fr(i, 0, adj[v[in]].size()) {
                if (vis[adj[v[in]][i]] == 0) {
                    vis[adj[v[in]][i]] = 3;
                } else if (vis[adj[v[in]][i]] == 2) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1) {
            cout << "NO" << endl;
            return 0;
        }
        // fr(i, 1, n + 1) {
        //     cout << vis[i] << " ";
        // }
        // cout << endl;

        for (lli i = 0; i < v.size(); i++) {
            lli x = vis[v[i]];
            if (x == 0) {
                flag = 1;
                break;
            }
        }

        lli two = 0, three = 0;
        fr(i, 1, n + 1) {
            if (vis[i] == 2) {
                two++;
            } else if (vis[i] == 3) {
                three++;
            } else {
                two++;
                three++;
            }
        }

        fr(i, 0, v.size()) {
            lli x = vis[v[i]];
            if (x != 1) {
                if (x == 2) {
                    if (adj[v[i]].size() != two - 1) {
                        flag = 1;
                        break;
                    }
                } else {
                    if (adj[v[i]].size() != three - 1) {
                        flag = 1;
                        break;
                    }
                }
                for (lli j = 0; j < adj[v[i]].size(); j++) {
                    if (vis[adj[v[i]][j]] != x && vis[adj[v[i]][j]] != 1) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1) {
                break;
            }
        }

        //     if (x != 1) {
        //         for (lli j = 0; j < adj[v[i]].size(); j++) {
        //             if (v[i] == 2) {
        //                 cout << adj[v[i]][j] << " ";
        //             }
        //             if (vis[adj[v[i]][j]] != x && vis[adj[v[i]][j]] != 1) {
        //                 flag = 1;
        //                 break;
        //             }
        //         }
        //     }
        //     if (flag == 1) {
        //         break;
        //     }
        // }

        if (flag == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            fr(i, 1, n + 1) {
                if (vis[i] == 1) {
                    cout << "b";
                } else if (vis[i] == 2) {
                    cout << "a";
                } else {
                    cout << "c";
                }
            }
            cout << endl;
        }
    }
    rt;
}
