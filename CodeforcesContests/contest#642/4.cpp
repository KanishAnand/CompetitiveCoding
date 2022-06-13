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
    lli n, a;
    cin >> n;
    set<pair<lli, pair<lli, lli>>> st;
    st.insert({-(n - 1 + 1), {1, n}});
    vector<lli> ans(n + 2, 0);
    lli val = 1;

    while (!st.empty()) {
        auto it = st.begin();
        pair<lli, pair<lli, lli>> p = *it;
        lli start = p.second.first;
        lli fin = p.second.second;
        lli mid = (start + fin) / 2;
        // cout << start << " " << fin << " " << mid << endl;
        ans[mid] = val;
        val++;
        st.erase(it);
        if (start <= mid - 1) {
            st.insert({-(mid - start), {start, mid - 1}});
        }
        if (mid + 1 <= fin) {
            // cout << mid + 1 << " " << fin << endl;
            st.insert({-(fin - mid), {mid + 1, fin}});
        }
    }

    for (lli i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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