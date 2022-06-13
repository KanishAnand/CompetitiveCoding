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
    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        cin >> a;

        if (mp[a] == 0) {
            v.pb(a);
        }
        mp[a]++;
    }

    multiset<lli> st;
    for (lli i = 0; i < sz(v); i++) {
        st.insert(mp[v[i]]);
    }

    while (sz(st) > 1) {
        auto it1 = st.end();
        auto it2 = st.end();
        it1--;
        it2--;
        it2--;
        lli val1 = *it1;
        lli val2 = *it2;

        st.erase(it1);
        st.erase(it2);
        val1--;
        val2--;
        if (val1 != 0) {
            st.insert(val1);
        }
        if (val2 != 0) {
            st.insert(val2);
        }
    }

    if (sz(st) == 0) {
        cout << "0" << endln;
    } else {
        lli ans = *(st.begin());
        cout << ans << endln;
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