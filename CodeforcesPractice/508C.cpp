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
    lli m, t, r, a;
    cin >> m >> t >> r;
    vector<lli> v;

    for (lli i = 0; i < m; i++) {
        cin >> a;
        v.pb(a);
    }

    if (t < r) {
        cout << "-1" << endl;
        return;
    }

    lli p = 1, ans = r;
    set<lli> st;

    for (lli i = 0; i < r; i++) {
        st.insert(v[0] - p);
        p++;
    }

    for (lli i = 1; i < m; i++) {
        lli no = 0;
        for (auto it = st.begin(); it != st.end(); it++) {
            if (*it + t < v[i]) {
                no++;
            }
        }

        lli p = no;
        while (p > 0) {
            auto it = st.begin();
            st.erase(it);
            p--;
        }
        p = no;
        lli x = 1;
        while (p > 0) {
            st.insert(v[i] - x);
            x++;
            p--;
        }
        ans += no;
    }

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