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
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli q;
    cin >> q;

    vector<lli> v;
    multiset<lli> st;
    lli beg = 0;

    lli a, x;
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> x;
            v.pb(x);
        } else if (a == 2) {
            if (sz(st) != 0) {
                auto it = st.begin();
                cout << *it << endln;
                st.erase(it);
            } else {
                cout << v[beg] << endln;
                beg++;
            }
        } else {
            lli n = sz(v);
            for (lli i = beg; i < n; i++) {
                st.insert(v[i]);
            }
            beg = n;
        }
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