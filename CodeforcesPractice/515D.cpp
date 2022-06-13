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

vector<set<int>> adj(4e6 + 2);
queue<int> qu;

void solve() {
    int n, a, m;
    cin >> n >> m;
    string st;
    vector<string> store;
    for (int i = 0; i < n; i++) {
        cin >> st;
        store.pb(st);
    }

    map<int, int> mpx;
    map<int, int> mpy;

    int cnt = 0, p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt++;
            if (store[i][j] == '.') {
                p++;
                mpx[cnt] = i;
                mpy[cnt] = j;
                int p = 0;
                if (i != 0 && store[i - 1][j] == '.') {
                    adj[cnt].insert(cnt - m);
                }
                if (i != n - 1 && store[i + 1][j] == '.') {
                    adj[cnt].insert(cnt + m);
                }
                if (j != 0 && store[i][j - 1] == '.') {
                    adj[cnt].insert(cnt - 1);
                }
                if (j != m - 1 && store[i][j + 1] == '.') {
                    adj[cnt].insert(cnt + 1);
                }

                if (adj[cnt].size() == 0) {
                    cout << "Not unique" << endl;
                    return;
                }
            }
        }
    }

    if (p == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << store[i][j];
            }
            cout << endln;
        }
        return;
    }

    for (int i = 1; i <= cnt; i++) {
        if (adj[i].size() == 1) {
            qu.push(i);
        }
    }

    if (qu.size() == 0) {
        cout << "Not unique" << endl;
        return;
    }

    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        if (sz(adj[a]) != 1) {
            continue;
        }
        int val = *(adj[a].begin());

        int x1 = mpx[a], y1 = mpy[a];
        int x2 = mpx[val], y2 = mpy[val];
        if (x1 == x2) {
            if (y1 < y2) {
                store[x1][y1] = '<';
                store[x1][y2] = '>';
            } else {
                store[x1][y2] = '<';
                store[x1][y1] = '>';
            }
        }

        if (y1 == y2) {
            if (x1 < x2) {
                store[x1][y1] = '^';
                store[x2][y1] = 'v';
            } else {
                store[x2][y1] = '^';
                store[x1][y1] = 'v';
            }
        }

        for (auto vv : adj[a]) {
            if (adj[vv].find(a) != adj[vv].end()) {
                adj[vv].erase(a);
                if (sz(adj[vv]) == 1) {
                    qu.push(vv);
                }
            }
        }
        for (auto vv : adj[val]) {
            if (adj[vv].find(val) != adj[vv].end()) {
                adj[vv].erase(val);
                if (sz(adj[vv]) == 1) {
                    qu.push(vv);
                }
            }
        }

        adj[a].clear();
        adj[val].clear();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (store[i][j] == '.') {
                cout << "Not unique" << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << store[i][j];
        }
        cout << endln;
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