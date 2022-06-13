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
    lli n, a;
    cin >> n;
    vector<lli> v;
    set<lli> st;
    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a] = i;
        st.insert(a);
        v.pb(a);
    }

    lli last = n - 1;
    lli prev = sz(st);

    while (!st.empty()) {
        auto it = st.begin();
        lli val = *it;
        lli ind = mp[val];
        for (lli i = ind; i <= last; i++) {
            lli no = v[i];
            if (st.find(no) != st.end()) {
                st.erase(no);
            }
        }
        v[ind] = v[last];
        mp[v[ind]] = ind;
        st.insert(v[ind]);
        last = ind;
        lli nw = sz(st);
        if (nw == prev) {
            break;
        }
        prev = nw;
    }

    if (sz(st) <= 1) {
        cout << "YES" << endln;
    } else {
        cout << "NO" << endln;
    }
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