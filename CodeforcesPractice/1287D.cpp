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
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<endl;

// lli power(lli x, lli y) {
//     // return (x^y) % mod
//     lli ans = 1;
//     x = x % mod;
//     while (y > 0) {
//         if (y & 1) {
//             ans *= x;
//             ans %= mod;
//         }
//         y = y >> 1;
//         x = (x * x) % mod;
//     }
//     return ans;
// }

// handle case for ans no

vector<lli> v;
vector<lli> vis, ans;
vector<vector<lli>> adj;
lli valu = 2100;

vector<lli> dfs(lli a) {
    vector<lli> st;
    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        vis[val] = 1;
        vector<lli> ts = dfs(val);
        fr(j, 0, ts.size()) {
            st.pb(ts[j]);
        }
    }

    if (st.size() == 0) {
        if (v[a] > 0) {
            cout << "NO" << endl;
            exit(0);
        }
        ans[a] = valu;
        st.pb(valu);
        valu += 2100;
    } else {
        sort(all(st));
        lli p = v[a];
        if (p > st.size()) {
            cout << "NO" << endl;
            exit(0);
        }
        lli q;
        if (p == 0) {
            q = st[0] - 1;
        } else {
            q = st[p - 1] + 1;
        }
        ans[a] = q;
        st.pb(q);
    }
    return st;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a;
    cin >> n;
    lli p, c, root;
    adj.resize(n + 2);
    v.pb(0);

    fr(i, 0, n) {
        cin >> p >> c;
        adj[p].pb(i + 1);
        if (p == 0) {
            root = i + 1;
        }
        v.pb(c);
    }

    vis.resize(n + 3, 0);
    ans.resize(n + 3, 0);
    vis[root] = 1;
    dfs(root);
    cout << "YES" << endl;
    fr(i, 1, n + 1) {
        cout << ans[i] << " ";
    }
    cout << endl;
    rt;
}
