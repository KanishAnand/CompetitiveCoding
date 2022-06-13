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

vector<vector<lli>> adj;
vector<lli> vis, v;
lli ans, mx = -1, flag = 0, an;

lli dfs(lli a, lli cnt) {
    if (cnt > mx) {
        mx = cnt;
        ans = a;
    }
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            ++cnt;
            dfs(val, cnt);
            --cnt;
        }
    }
    return 0;
}

lli dfs_3(lli a, lli cnt) {
    if (cnt > mx) {
        mx = cnt;
        an = a;
    }
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (v[val] == 0) {
            v[val] = 1;
            ++cnt;
            dfs_3(val, cnt);
            --cnt;
        }
    }
    return 0;
}

lli dfs_2(lli a, stack<lli> &st, lli cnt) {
    if (cnt == mx) {
        flag = 1;
    }
    fr(i, 0, adj[a].size()) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            ++cnt;
            if (flag == 0) {
                v[val] = 1;
                st.push(val);
            }
            dfs_2(val, st, cnt);
            --cnt;
            if (flag == 0) {
                v[val] = 0;
                st.pop();
            }
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, b, c;
    cin >> n;
    adj.resize(n + 2);

    fr(i, 0, n - 1) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vis.resize(n + 2, 0);
    v.resize(n + 2, 0);
    vis[1] = 1;
    dfs(1, 0);
    // cout << ans << endl;
    a = ans;
    fill(vis.begin(), vis.end(), 0);
    vis[ans] = 1;
    mx = -1;
    dfs(ans, 0);
    b = ans;
    fill(vis.begin(), vis.end(), 0);
    stack<lli> st;
    st.push(a);
    vis[a] = 1;
    v[a] = 1;
    dfs_2(a, st, 0);
    lli len = mx, ln = -1;

    while (!st.empty()) {
        mx = -1;
        dfs_3(st.top(), 0);
        if (mx > ln) {
            ln = mx;
            c = an;
        }
        st.pop();
    }
    if (ln > 0) {
        cout << len + ln << endl;
        cout << a << " " << b << " " << c << endl;
    } else {
        cout << len << endl;
        if (a != 1 && b != 1) {
            c = 1;
        } else if (a != 2 && b != 2) {
            c = 2;
        } else {
            c = 3;
        }
        cout << a << " " << b << " " << c << endl;
    }

    rt;
}