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
    vector<lli> v, v2;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v2.pb(a);
        lli val = a;
        if (val < 0) {
            val = -a;
        }
        val %= n;
        if (a >= 0) {
            v.pb(val);
        } else {
            v.pb(-val);
        }
    }

    map<lli, lli> mp;
    lli flag = 0;

    for (lli i = 0; i < 3 * n; i++) {
        lli val = v2[i % n] + i;
        if (val >= n && val < 2 * n) {
            mp[val]++;
            if (mp[val] > 1) {
                flag = 1;
                break;
            }
        } else {
            val = v[i % n] + i;
            mp[val]++;
            if (mp[val] > 1) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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