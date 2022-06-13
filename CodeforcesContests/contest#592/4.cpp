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
    lli n, a;
    vector<lli> v1, v2, v3, v, vis;
    cin >> n;
    vis.resize(n + 2, 0);
    v1.pb(0);
    v2.pb(0);
    v3.pb(0);

    input(n, v1);
    input(n, v2);
    input(n, v3);
    vector<vector<lli>> adj;
    adj.resize(n + 2);
    lli b;
    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    lli p;
    for (lli i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            p = i;
        }
        if (adj[i].size() >= 3) {
            cout << "-1" << endl;
            return 0;
        }
    }

    lli val = p;
    v.pb(p);
    // cout << p << "K" << endl;
    vis[p] = 1;
    val = adj[p][0];
    vis[val] = 1;
    v.pb(val);
    while (1) {
        if (adj[val].size() == 1) {
            break;
        }
        lli x = adj[val][0];
        lli y = adj[val][1];
        if (vis[x] == 1) {
            val = y;
            vis[val] = 1;
        } else {
            val = x;
            vis[val] = 1;
        }
        v.pb(val);
    }

    lli minn = 1e16;
    // fr(i, 0, v.size()) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    lli in;
    for (lli j = 0; j < 6; j++) {
        lli ans = 0;
        for (lli i = 0; i < v.size(); i++) {
            // cout << i << "L" << endl;

            lli x = v[i];
            if (i % 3 == 0) {
                if (j == 0 || j == 1) {
                    ans += v1[x];
                } else if (j == 2 || j == 3) {
                    ans += v2[x];
                } else {
                    ans += v3[x];
                }
            } else if (i % 3 == 1) {
                if (j == 2 || j == 4) {
                    ans += v1[x];
                } else if (j == 0 || j == 5) {
                    ans += v2[x];
                } else {
                    ans += v3[x];
                }
            } else {
                if (j == 3 || j == 5) {
                    ans += v1[x];
                } else if (j == 1 || j == 4) {
                    ans += v2[x];
                } else {
                    ans += v3[x];
                }
            }
            // cout << ans << endl;
        }

        if (ans < minn) {
            minn = ans;
            in = j;
            // cout << minn << " " << j << endl;
        }
    }
    vector<lli> an(n + 2, 0);
    fr(i, 0, v.size()) {
        an[v[i]] = i;
    }
    // if(in == 0){
    // fr(i, 0, v.size()) {
    //     cout << v[i] << " ";
    // }
    // cout << in << endl;
    // }
    cout << minn << endl;
    if (in == 0) {
        for (lli i = 1; i <= n; i++) {
            if (an[i] % 3 == 0) {
                cout << "1"
                     << " ";
            } else if (an[i] % 3 == 1) {
                cout << "2"
                     << " ";
            } else {
                cout << "3"
                     << " ";
            }
        }
    } else if (in == 1) {
        for (lli i = 1; i <= n; i++) {
            if (an[i] % 3 == 0) {
                cout << "1"
                     << " ";
            } else if (an[i] % 3 == 1) {
                cout << "3"
                     << " ";
            } else {
                cout << "2"
                     << " ";
            }
        }
    } else if (in == 2) {
        for (lli i = 1; i <= n; i++) {
            if (an[i] % 3 == 0) {
                cout << "2"
                     << " ";
            } else if (an[i] % 3 == 1) {
                cout << "1"
                     << " ";
            } else {
                cout << "3"
                     << " ";
            }
        }
    } else if (in == 3) {
        for (lli i = 1; i <= n; i++) {
            if (an[i] % 3 == 0) {
                cout << "2"
                     << " ";
            } else if (an[i] % 3 == 1) {
                cout << "3"
                     << " ";
            } else {
                cout << "1"
                     << " ";
            }
        }
    } else if (in == 4) {
        for (lli i = 1; i <= n; i++) {
            // cout << an[i] << ;
            if (an[i] % 3 == 0) {
                cout << "3"
                     << " ";
            } else if (an[i] % 3 == 1) {
                cout << "1"
                     << " ";
            } else {
                cout << "2"
                     << " ";
            }
        }
    } else if (in == 5) {
        for (lli i = 1; i <= n; i++) {
            if (an[i] % 3 == 0) {
                cout << "3"
                     << " ";
            } else if (an[i] % 3 == 1) {
                cout << "2"
                     << " ";
            } else {
                cout << "1"
                     << " ";
            }
        }
    }
    cout << endl;
    rt;
}
