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
    lli n, c, p, a;
    cin >> n;
    vector<pair<pair<lli, lli>, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> c >> p;
        v.pb({{p, c}, i + 1});
    }

    sort(all(v));
    reverse(all(v));

    lli k;
    cin >> k;
    set<pair<lli, lli>> st;
    for (lli i = 0; i < k; i++) {
        cin >> a;
        st.insert({a, i + 1});
    }

    lli tot = 0;
    vector<pair<lli, lli>> ans;

    for (lli i = 0; i < n; i++) {
        if (st.empty()) {
            break;
        }
        auto it = st.lower_bound({v[i].first.second, -1});
        if (it != st.end()) {
            ans.pb({v[i].second, it->second});
            tot += v[i].first.first;
            st.erase(it);
        }
    }

    cout << ans.size() << " " << tot << endl;
    for (lli i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
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