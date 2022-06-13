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

lli fun(lli a) {
    lli val = (a * (a - 1)) / 2;
    return val;
}

void solve() {
    lli n, a, k;
    cin >> n >> k;

    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli no = pow(2, k) - 1;
    map<lli, lli> mp;

    for (lli i = 0; i < n; i++) {
        if (i) {
            v[i] ^= v[i - 1];
        }
        lli val = min(v[i], v[i] ^ no);
        mp[val]++;
    }

    lli ans = (n * (n + 1)) / 2;
    for (auto val : mp) {
        lli cnt = val.second;
        if (val.first == 0) {
            ans -= cnt / 2;
        }
        ans -= fun(cnt / 2);
        ans -= fun(cnt / 2 + cnt % 2);
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