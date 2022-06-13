#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<pair<lli, lli>, null_type, less<pair<lli, lli>>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a, t;
    cin >> n >> t;

    lli sum = 0, ans = 0;
    new_data_set st;
    st.insert({0, -1});

    for (lli i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        lli val = sum - t;
        lli no = st.order_of_key({val, i});
        ans += sz(st) - no;
        st.insert({sum, i});
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