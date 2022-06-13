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
vector<vector<lli>> adj;
vector<lli> vis;
vector<lli> cycle_final;
lli cyc = 0;

void dfs(lli a, stack<lli> &cycle) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            if (cyc == 0) {
                cycle.push(val);
            }
            dfs(val, cycle);
            vis[val] = 2;
            if (cyc == 0) {
                cycle.pop();
            }
        } else if (vis[val] == 1 && cyc == 0) {
            cyc = 1;
            a = cycle.top();
            while (a != val) {
                cycle_final.pb(a);
                cycle.pop();
                a = cycle.top();
            }
            cycle_final.pb(val);
            return;
        }
    }
}

void solve() {
    lli n, a;
    cin >> n;
    string st;
    adj.resize(n + 2);
    vector<string> store;

    for (lli i = 1; i <= n; i++) {
        cin >> st;
        store.pb(st);
        for (lli j = 1; j <= n; j++) {
            if (st[j - 1] == '1') {
                adj[i].pb(j);
            }
        }
    }

    vis.resize(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        stack<lli> cycle;
        if (vis[i] == 0) {
            vis[i] = 1;
            cycle.push(i);
            dfs(i, cycle);
            vis[i] = 2;
            if (cyc == 1) {
                break;
            }
            cycle.pop();
        }
    }

    if (cyc == 0) {
        cout << "-1" << endl;
        return;
    }

    reverse(all(cycle_final));

    lli b, c;
    lli bi = 1, ci = 2;
    a = cycle_final[0];
    b = cycle_final[1];
    c = cycle_final[2];
    while (1) {
        if (store[c - 1][a - 1] == '1') {
            cout << a << " " << b << " " << c << endl;
            return;
        } else {
            bi++;
            ci++;
            b = cycle_final[bi];
            c = cycle_final[ci];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}