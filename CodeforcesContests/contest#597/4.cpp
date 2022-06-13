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
lli dfs_go(lli a);
lli dfs();
lli dfs_go_trans(lli a);
lli dfs_trans();
stack<lli> topo;
vector<vector<lli>> adj;
vector<vector<lli>> trans;
lli arr[100005] = {0};
vector<lli> xc, yc, cost, k;
lli n;
lli mn = 1e10;
lli mx = -1, ans = 0, temp, ans2 = 0;

lli dfs_trans() {
    lli i, cnt = 1;
    while (cnt <= n) {
        mn = 1e10;
        mx = -1;
        temp = 0;
        if (arr[topo.top()] == 0) {
            ans2++;
            i = topo.top();
            arr[i] = 1;
            // cout << dfs_go_trans(i) << " ";
            lli val = dfs_go_trans(i);
            if (cost[val - 1] < mn) {
                mn = cost[val - 1];
            }
            // cout << endl;
            ans += mn;
            ans -= mx;
            arr[i] = 2;
        }
        topo.pop();
        ++cnt;
    }

    return 0;
}

lli dfs_go_trans(lli a) {
    if (trans[a].size() == 0) {
        arr[a] = 2;
        return a;
    }

    for (lli i = 0; i < trans[a].size(); i++) {
        if (arr[trans[a][i]] == 0) {
            arr[trans[a][i]] = 1;
            lli t = trans[a][i];
            lli var = abs(xc[t - 1] - xc[a - 1]) + abs(yc[t - 1] - yc[a - 1]);
            var *= k[t - 1] + k[a - 1];
            ans += var;
            if (var > mx) {
                mx = var;
            }
            // cout << dfs_go_trans(trans[a][i]) << " ";
            lli val = dfs_go_trans(trans[a][i]);
            if (cost[val - 1] < mn) {
                mn = cost[val - 1];
            }
            arr[trans[a][i]] = 2;
        }
    }
    arr[a] = 2;
    return a;
}

lli dfs() {
    for (lli i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
            // start_time[i] = t;
            // ++t;
            topo.push(dfs_go(i));
            // finish_time.insert(t,i);
            // ++t;
            arr[i] = 2;
        }
    }
    return 0;
}

lli dfs_go(lli a) {
    if (adj[a].size() == 0) {
        arr[a] = 2;
        return a;
    }

    for (lli i = 0; i < adj[a].size(); i++) {
        if (arr[adj[a][i]] == 0) {
            arr[adj[a][i]] = 1;
            topo.push(dfs_go(adj[a][i]));
            arr[adj[a][i]] = 2;
        }
    }
    arr[a] = 2;
    return a;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli a;
    cin >> n;
    lli x, y;
    fr(i, 0, n) {
        cin >> x >> y;
        xc.pb(x);
        yc.pb(y);
    }
    fr(i, 0, n) {
        cin >> a;
        cost.pb(a);
    }
    fr(i, 0, n) {
        cin >> a;
        k.pb(a);
    }

    // vector<vector<lli>> adj;
    // adj[j + 1].pb(i + 1);
    adj.resize(n + 2);
    trans.resize(n + 2);

    for (lli i = 0; i < n; i++) {
        lli mn = 1000000000, val;
        for (lli j = 0; j < n; j++) {
            if (j != i) {
                lli dis = abs(xc[j] - xc[i]) + abs(yc[j] - yc[i]);
                if (dis < mn) {
                    mn = dis;
                    val = j;
                }
            }
        }
        adj[i + 1].pb(val + 1);
        trans[val + 1].pb(i + 1);
    }

    dfs();
    for (int i = 1; i <= n + 2; i++) {
        arr[i] = 0;
    }
    dfs_trans();
    cout << ans << endl;
    cout << ans2 << endl;
    rt;
}
