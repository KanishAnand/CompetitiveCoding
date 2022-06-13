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

void solve() {
    lli n, a, k, b;
    cin >> n >> k;

    vector<set<lli>> adj(n + 2);
    vector<lli> deg(n + 2, 0);

    for (lli i = 0; i < n - 1; i++) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<lli> leaf(n + 2, 0);
    for (lli i = 1; i <= n; i++) {
        for (auto val : adj[i]) {
            if (deg[val] == 1) {
                leaf[i]++;
            }
        }
    }

    set<pair<lli, lli>> st;

    for (lli i = 1; i <= n; i++) {
        st.insert({leaf[i], i});
    }

    lli ans = 0;
    while (!st.empty()) {
        auto it = st.end();
        it--;
        a = it->first;
        b = it->second;
        st.erase(it);

        if (a < k) {
            break;
        }

        ans++;
        vector<lli> tmp;
        for (auto itt = adj[b].begin(); itt != adj[b].end(); itt++) {
            if (tmp.size() == k) {
                break;
            }
            if (deg[*itt] == 1) {
                tmp.pb(*itt);
            }
        }

        for (auto val : tmp) {
            auto itt = adj[b].find(val);
            adj[b].erase(itt);
            auto it2 = st.find({leaf[val], val});
            st.erase(it2);
        }

        deg[b] -= k;
        leaf[b] -= k;

        if (deg[b] >= 1) {
            st.insert({leaf[b], b});
        }
        if (deg[b] == 1) {
            auto itt = adj[b].begin();
            auto it2 = st.find({leaf[*itt], *itt});
            st.erase(it2);
            leaf[*itt]++;
            st.insert({leaf[*itt], *itt});
        }
    }

    cout << ans << endln;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}