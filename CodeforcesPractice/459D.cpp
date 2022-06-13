#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
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
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

lli input(lli n, vector<lli> &ve);
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
    lli n, a;
    vector<lli> v;
    cin >> n;
    input(n, v);
    new_data_set st, st1;
    unordered_map<lli, lli> mp, mp1;

    for (lli i = n - 1; i >= 0; i--) {
        mp[v[i]]++;
        st.insert(mp[v[i]]);
    }

    lli ans = 0;

    for (lli i = 0; i < n - 1; i++) {
        mp1[v[i]]++;
        st1.insert(mp[v[i]]);
        lli val1 = st.order_of_key(mp1[v[i]]);
        lli val2 = st1.order_of_key(mp1[v[i]]);
        ans += (val1 - val2);
        mp[v[i]]--;
    }
    cout << ans << endl;
    rt;
}