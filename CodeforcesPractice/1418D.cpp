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
    lli n, a, q, b;
    cin >> n >> q;

    vector<lli> v;
    multiset<lli> st, diff;
    diff.insert(0);

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        st.insert(a);
    }

    sort(all(v));

    for (lli i = 0; i < n - 1; i++) {
        diff.insert(v[i + 1] - v[i]);
    }

    q++;
    lli flag = 0;

    while (q--) {
        if (flag == 1) {
            cin >> a >> b;
            if (a == 0) {
                lli x = -1, y = -1;
                st.erase(st.find(b));
                auto it1 = st.lower_bound(b);
                auto it2 = st.upper_bound(b);

                if (it1 != st.begin()) {
                    it1--;
                    x = *it1;
                    diff.erase(diff.find(b - x));
                }
                if (it2 != st.end()) {
                    y = *it2;
                    diff.erase(diff.find(y - b));
                }
                if (x != -1 && y != -1) {
                    diff.insert(y - x);
                }
            } else {
                lli x = -1, y = -1;
                auto it1 = st.lower_bound(b);
                auto it2 = st.upper_bound(b);

                if (it1 != st.begin()) {
                    it1--;
                    x = *it1;
                    diff.insert(b - x);
                }
                if (it2 != st.end()) {
                    y = *it2;
                    diff.insert(y - b);
                }
                if (x != -1 && y != -1) {
                    diff.erase(diff.find(y - x));
                }
                st.insert(b);
            }
        }

        auto it = diff.end();
        it--;

        lli ans = 0;

        if (st.size() != 0) {
            auto itt = st.end();
            itt--;

            ans = *itt - *(st.begin());
        }

        ans -= *it;
        cout << ans << endl;
        flag = 1;
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