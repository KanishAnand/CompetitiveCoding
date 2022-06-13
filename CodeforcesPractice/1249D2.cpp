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
    lli n, a, k, l, r;
    cin >> n >> k;
    vector<pair<lli, lli>> v;

    vector<vector<pair<lli, lli>>> store_start(2e5 + 2), store_end(2e5 + 2);

    vector<lli> cnt(2e5 + 2, 0);

    for (lli i = 0; i < n; i++) {
        cin >> l >> r;
        v.pb({l, r});
        store_start[l].pb({r, i + 1});
        store_end[r + 1].pb({r, i + 1});
        cnt[l]++;
        cnt[r + 1]--;
    }

    vector<lli> ans;
    vector<lli> vis(2e5 + 2, 0);
    set<pair<lli, lli>> st;
    lli sum = 0;

    for (lli i = 1; i <= 2e5; i++) {
        for (lli j = 0; j < store_start[i].size(); j++) {
            st.insert(store_start[i][j]);
        }
        for (lli j = 0; j < store_end[i].size(); j++) {
            if (vis[store_end[i][j].second] == 0) {
                st.erase(store_end[i][j]);
            }
        }

        sum += cnt[i];
        while (sum > k) {
            auto it = st.end();
            it--;
            cnt[it->first + 1]++;
            ans.pb(it->second);
            vis[it->second] = 1;
            st.erase(it);
            sum--;
        }
    }

    cout << ans.size() << endl;
    for (lli i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
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