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
    lli n, k;
    cin >> n >> k;

    vector<lli> v;
    lli no = 1, flag = 0;

    for (lli i = 0; i < n; i++) {
        v.pb(no);
        if (flag == 0) {
            no++;
        }
        if (no == k + 1) {
            flag = 1;
            no = k;
        }
        if (flag == 1) {
            no--;
        }
    }

    vector<lli> fin;

    for (lli i = 1; i < v[n - 1]; i++) {
        fin.pb(i);
    }

    for (lli i = k; i >= v[n - 1]; i--) {
        fin.pb(i);
    }

    for (lli i = v[n - 1] + 1; i <= k; i++) {
        fin.pb(i);
    }

    // for (lli i = 0; i < sz(v); i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // for (lli i = 0; i < sz(fin); i++) {
    //     cout << fin[i] << " ";
    // }
    // cout << endl;

    map<lli, lli> mp;
    for (lli i = 0; i < n; i++) {
        mp[v[i]] = fin[i];
    }

    for (lli i = 1; i <= k; i++) {
        cout << mp[i] << " ";
    }
    cout << endl;
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