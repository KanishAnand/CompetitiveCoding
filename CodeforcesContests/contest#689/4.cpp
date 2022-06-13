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

void fun(lli l, lli r, vector<lli> &v, vector<lli> &pref, map<lli, lli> &mp) {
    lli val = pref[r] - pref[l] + v[l];
    if (val <= 1e9) {
        mp[val]++;
    }
    if (r - l + 1 <= 1) {
        return;
    }

    lli mid = (v[l] + v[r]) / 2;
    auto it = upper_bound(v.begin(), v.end(), mid);
    if (it == v.end()) {
        return;
    }
    lli ind = it - v.begin();
    if (ind == l || ind > r) {
        return;
    }
    fun(l, ind - 1, v, pref, mp);
    fun(ind, r, v, pref, mp);
}

void solve() {
    lli n, q, a;
    cin >> n >> q;

    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    map<lli, lli> mp;
    sort(all(v));
    vector<lli> pref(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        if (i != 0) {
            pref[i] = pref[i - 1];
        }
        pref[i] += v[i];
    }

    fun(0, n - 1, v, pref, mp);

    while (q--) {
        cin >> a;
        if (mp[a] == 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
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