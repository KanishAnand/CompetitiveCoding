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
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli mn = 1e10, ind = -1;
    vector<lli> pref(n + 2, -1);

    for (lli i = 0; i < n; i++) {
        if (mn < v[i]) {
            pref[i] = ind;
        }
        if (v[i] < mn) {
            mn = v[i];
            ind = i;
        }
    }

    mn = 1e10, ind = -1;
    vector<lli> suff(n + 2, -1);

    for (lli i = n - 1; i >= 0; i--) {
        if (mn < v[i]) {
            suff[i] = ind;
        }
        if (v[i] < mn) {
            mn = v[i];
            ind = i;
        }
    }

    for (lli i = 0; i < n; i++) {
        if (pref[i] != -1 && suff[i] != -1) {
            cout << "YES" << endln;
            cout << pref[i] + 1 << " " << i + 1 << " " << suff[i] + 1 << endln;
            return;
        }
    }

    cout << "NO" << endl;
    return;
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