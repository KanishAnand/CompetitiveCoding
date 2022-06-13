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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

bool cycle = 0;
stack<lli> topo;
vector<lli> vis;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            vis[val] = 2;
            topo.push(val);
        } else if (vis[val] == 1) {
            cycle = 1;
            return;
        }
    }
}

void solve() {
    string st;
    lli n, m, k, no;
    cin >> n >> m >> k;

    vector<pair<string, lli>> patterns;

    for (lli i = 0; i < n; i++) {
        cin >> st;
        patterns.pb({st, i + 1});
    }
    sort(all(patterns));

    adj.resize(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> st >> no;
        lli flag = 0;
        for (lli mask = 0; mask < pow(2, k); mask++) {
            string ptrn = "";
            lli tmp_no = mask, ind = 0;

            while (tmp_no > 0) {
                lli rem = tmp_no % 2;
                if (rem == 1) {
                    ptrn += st[ind];
                } else {
                    ptrn += '_';
                }
                tmp_no /= 2;
                ind++;
            }
            while (len(ptrn) < k) {
                ptrn += '_';
            }

            pair<string, lli> pr = {ptrn, -1};
            auto it = lower_bound(patterns.begin(), patterns.end(), pr);
            if (it != patterns.end()) {
                auto chk = *it;
                if (chk.first == ptrn) {
                    if (chk.second == no) {
                        flag = 1;
                    } else {
                        adj[no].pb(chk.second);
                    }
                }
            }
        }

        if (flag == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    vis.resize(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            vis[i] = 2;
            topo.push(i);
            if (cycle == 1) {
                break;
            }
        }
    }

    if (cycle) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    while (!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
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