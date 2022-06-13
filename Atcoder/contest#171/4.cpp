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
    lli n, a, q;
    cin >> n;
    vector<lli> v;
    lli sum = 0;

    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        mp[a]++;
        v.pb(a);
    }
    cin >> q;

    lli b, c;
    while (q--) {
        cin >> b >> c;
        lli val1 = mp[b];
        sum -= val1 * b;
        sum += val1 * c;
        mp[b] = 0;
        mp[c] += val1;
        cout << sum << endl;
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