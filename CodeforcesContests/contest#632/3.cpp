#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
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

    map<lli, lli> mp;

    mp[0] = -1;
    lli zero = 0;

    lli sum = 0, prev = 1, ans = 0, flag = 0, st = 0;

    for (lli i = 0; i < n; i++) {
        sum += v[i];

        if (mp[sum] != 0) {
            if (mp[sum] == -1) {
                mp[sum] = 0;
            }

            lli cur = i + 1 - 1;
            lli no = cur - prev + 1;
            if (no > 0) {
                ans += (no * (no + 1)) / 2;
            }

            ans -= (st * (st + 1)) / 2;

            lli val = mp[sum] + 2;
            prev = max(prev, val);
            st = max(zero, i + 1 - prev);
        }

        mp[sum] = i + 1;
    }

    ans -= (st * (st + 1)) / 2;
    lli no = n - prev + 1;
    if (no > 0) {
        ans += (no * (no + 1)) / 2;
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