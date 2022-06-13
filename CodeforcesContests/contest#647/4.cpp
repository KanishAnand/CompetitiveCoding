#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
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

void solve() {
    lli n, a, m, b;
    cin >> n >> m;

    vector<vector<lli>> adj(n + 2);

    for (lli i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb({a, i + 1});
    }

    sort(all(v));
    vector<lli> ans, col(n + 2, 0);
    lli flag = 0;

    for (lli i = 0; i < sz(v); i++) {
        b = v[i].first;
        a = v[i].second;

        set<lli> st;
        for (auto val : adj[a]) {
            if (col[val] != 0) {
                st.insert(col[val]);
            }
            if (col[val] == b) {
                cout << "-1" << endl;
                exit(0);
            }
        }

        if (st.size() != b - 1) {
            flag = 1;
            break;
        } else {
            col[a] = b;
            ans.pb(a);
        }
    }

    if (flag == 1) {
        cout << "-1" << endl;
    } else {
        for (lli i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
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