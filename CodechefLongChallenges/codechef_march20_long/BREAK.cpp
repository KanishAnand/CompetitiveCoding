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

lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, t, s;
    cin >> t >> s;
    while (t--) {
        cin >> n;
        vector<lli> x, y;
        input(n, x);
        input(n, y);
        sort(all(x));
        sort(all(y));
        set<lli> st;
        lli flag = 0;
        if (y[0] <= x[0]) {
            flag = 1;
            cout << "NO" << endl;
            continue;
        }

        st.insert(x[0]);
        st.insert(y[0]);

        fr(i, 1, n) {
            if (y[i] <= x[i]) {
                flag = 1;
                break;
            }
            auto it = st.find(x[i]);
            if (it == st.end()) {
                flag = 1;
                break;
            }

            st.insert(x[i]);
            st.insert(y[i]);
        }

        if (flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    rt;
}
