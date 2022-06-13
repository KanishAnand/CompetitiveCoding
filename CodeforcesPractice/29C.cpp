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
    lli n, a, b;
    cin >> n;
    vector<pair<lli, lli>> v;
    set<lli> st;
    map<lli, lli> mp, mp2;

    for (lli i = 0; i < n; i++) {
        cin >> a >> b;
        st.insert(a);
        st.insert(b);
        v.pb({a, b});
    }

    lli beg = 1;

    for (auto it = st.begin(); it != st.end(); it++) {
        mp[*it] = beg;
        mp2[beg] = *it;
        beg++;
    }

    vector<vector<lli>> adj(beg + 2);
    for (lli i = 0; i < n; i++) {
        a = mp[v[i].first];
        b = mp[v[i].second];
        adj[a].pb(b);
        adj[b].pb(a);
    }

    lli root;

    for (lli i = 1; i < beg; i++) {
        if (adj[i].size() == 1) {
            root = i;
            break;
        }
    }

    vector<lli> ans;
    vector<lli> vis(beg + 2, 0);

    queue<lli> qu;
    qu.push(root);
    vis[root] = 1;
    while (!qu.empty()) {
        a = qu.front();
        ans.pb(a);
        qu.pop();
        for (lli i = 0; i < adj[a].size(); i++) {
            lli val = adj[a][i];
            if (vis[val] == 0) {
                vis[val] = 1;
                qu.push(val);
            }
        }
    }

    for (lli i = 0; i < ans.size(); i++) {
        cout << mp2[ans[i]] << " ";
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