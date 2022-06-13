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
    vector<lli> v, flag;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    for (lli i = 0; i < n; i++) {
        cin >> a;
        flag.pb(a);
    }

    vector<lli> neg, pos;

    for (lli i = 0; i < n; i++) {
        if (flag[i] == 0) {
            if (v[i] < 0) {
                neg.pb(v[i]);
            } else {
                pos.pb(v[i]);
            }
        }
    }

    lli ind1 = 0, ind2 = 0;
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    for (lli i = 0; i < n; i++) {
        if (flag[i] == 0) {
            if (ind1 == pos.size()) {
                v[i] = neg[ind2];
                ind2++;
            } else {
                v[i] = pos[ind1];
                ind1++;
            }
        }
    }

    for (lli i = 0; i < n; i++) {
        cout << v[i] << " ";
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