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
vector<set<lli>> adj(26);
vector<bool> vis(26, 0);
lli cyc = 0;
string ans = "";

void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            ans += (char)(val + 'a');
            dfs(val);
        } else {
            cyc = 1;
            return;
        }
    }
}

void solve() {
    lli n, a;
    cin >> n;
    string st;
    vector<lli> store;
    vector<lli> in(26, 0);

    for (lli i = 0; i < n; i++) {
        cin >> st;
        if (st.length() == 1) {
            store.pb(st[0] - 'a');
            continue;
        }
        for (lli j = 0; j < st.length() - 1; j++) {
            adj[st[j] - 'a'].insert(st[j + 1] - 'a');
            in[st[j + 1] - 'a']++;
        }
    }

    vector<lli> cnt(26, 0);
    for (auto val : store) {
        if (adj[val].size() == 0 && in[val] == 0) {
            cnt[val] = 1;
        }
    }

    for (lli i = 0; i < 26; i++) {
        if (sz(adj[i]) > 1) {
            cout << "NO" << endl;
            return;
        }
    }

    for (lli i = 0; i < 26; i++) {
        if (vis[i] == 1) {
            continue;
        }
        if (cnt[i] == 1) {
            vis[i] = 1;
            ans += (char)(i + 'a');
        } else if (sz(adj[i]) == 1 && in[i] == 0) {
            vis[i] = 1;
            ans += (char)(i + 'a');
            dfs(i);
            if (cyc == 1) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (lli i = 0; i < 26; i++) {
        if ((sz(adj[i]) != 0 || in[i] != 0) && vis[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}