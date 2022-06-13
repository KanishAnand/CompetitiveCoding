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
    vector<lli> va, vb;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        va.pb(a);
    }
    for (lli i = 0; i < n; i++) {
        cin >> a;
        vb.pb(a);
    }
    lli pos = 0, neg = 0, flag = 1;

    for (lli i = 0; i < n; i++) {
        if (va[i] < vb[i]) {
            if (pos == 0) {
                flag = 0;
                break;
            }
        } else if (va[i] > vb[i]) {
            if (neg == 0) {
                flag = 0;
                break;
            }
        }
        if (va[i] == -1) {
            neg = 1;
        }
        if (va[i] == 1) {
            pos = 1;
        }
    }

    if (flag == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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