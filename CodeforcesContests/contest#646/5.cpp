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

vector<lli> vis;
vector<vector<lli>> adj;
vector<lli> initial, finl, cost;
multiset<lli> st;
lli ans = 0;
vector<lli> subx, suby;

lli dfs(lli a) {
    st.insert(cost[a]);

    for (lli i = 0; i < adj[a].size(); i++) {
        lli val = adj[a][i];
        if (vis[val] == 0) {
            vis[val] = 1;
            dfs(val);
            subx[a] += subx[val];
            suby[a] += suby[val];
            auto it = st.find(cost[val]);
            st.erase(it);
        }
    }

    if (initial[a] == 0 && finl[a] == 1) {
        subx[a]++;
    } else if (initial[a] == 1 && finl[a] == 0) {
        suby[a]++;
    }

    // cout << a << endl;
    lli val = *(st.begin());
    lli p = min(subx[a], suby[a]);
    // cout << p << " " << a << endl;
    ans += p * val * 2;
    subx[a] -= p;
    suby[a] -= p;
}

void solve() {
    lli n, a, b, c;
    cin >> n;
    adj.resize(n + 2);
    vis.resize(n + 2, 0);
    subx.resize(n + 2, 0);
    suby.resize(n + 2, 0);
    initial.resize(n + 2, 0);
    finl.resize(n + 2, 0);
    cost.resize(n + 2, 0);

    lli xx = 0, yy = 0;

    for (lli i = 1; i <= n; i++) {
        cin >> c >> a >> b;
        if (a == 0 && b == 1) {
            xx++;
        } else if (a == 1 && b == 0) {
            yy++;
        }
        cost[i] = c;
        initial[i] = a;
        finl[i] = b;
    }

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (xx != yy) {
        cout << "-1" << endl;
        return;
    }

    vis[1] = 1;
    dfs(1);
    // cout << subx[1] << " " << suby[1] << endl;

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}