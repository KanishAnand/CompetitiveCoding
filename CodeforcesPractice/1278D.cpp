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
const double PI = 3.14159265358979323846264338;
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
vector<bool> vis;
vector<vector<lli>> adj;

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
        }
    }
}

void solve() {
    lli n, a;
    cin >> n;
    adj.resize(n + 2);
    lli l, r;
    vector<pair<lli, lli>> v;
    for (lli i = 0; i < n; i++) {
        cin >> l >> r;
        v.pb({l, r});
    }

    sort(all(v));
    set<pair<lli, lli>> st;
    lli cnt = 0, flag = 0;

    for (lli i = 0; i < n; i++) {
        auto it = st.upper_bound({v[i].first, -1});
        for (auto itt = it; itt != st.end(); itt++) {
            lli val = itt->first;
            if (val < v[i].second) {
                cnt++;
                lli no = itt->second;
                adj[i + 1].pb(no);
                adj[no].pb(i + 1);
            } else {
                break;
            }
        }
        if (cnt >= n) {
            flag = 1;
            break;
        }
        st.insert({v[i].second, i + 1});
    }

    if (flag == 1 || cnt != n - 1) {
        cout << "NO" << endl;
        return;
    }

    vis.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1);
    for (lli i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}