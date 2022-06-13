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
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    vector<lli> ans(n + 2, -1);

    if (v[0] != 0) {
        ans[0] = 0;
    }

    set<lli> st;
    for (lli i = 0; i < v[n - 1]; i++) {
        st.insert(i);
    }

    for (lli i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            ans[i] = v[i - 1];
        }
    }

    for (lli i = 0; i < n; i++) {
        if (ans[i] != -1) {
            auto it = st.find(ans[i]);
            if (it != st.end()) {
                st.erase(it);
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        if (ans[i] == -1) {
            if (st.empty() == 1) {
                ans[i] = v[n - 1] + 1;
            } else {
                auto itt = st.begin();
                lli val = *itt;
                if (val == v[i]) {
                    if (st.size() != 1) {
                        itt++;
                        ans[i] = *itt;
                    } else {
                        ans[i] = v[n - 1] + 1;
                    }
                } else {
                    ans[i] = val;
                }
            }
        }
        auto it = st.find(ans[i]);
        if (it != st.end()) {
            st.erase(it);
        }
    }

    for (lli i = 0; i < n; i++) {
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