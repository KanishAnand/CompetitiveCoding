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
    set<lli> st;
    map<lli, lli> mp;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        st.insert(a);
    }

    while (1) {
        auto it = st.end();
        it--;
        lli val = *it;
        lli cp = val;
        while (val >= 1 && mp[val] != 0) {
            val /= 2;
        }

        if (val == 0) {
            break;
        } else {
            mp[cp]--;
            mp[val]++;
            st.erase(cp);
            st.insert(val);
        }
    }

    for (auto val : st) {
        cout << val << " ";
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