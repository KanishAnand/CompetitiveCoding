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
    lli n1, n2, n3;
    cin >> n3 >> n2 >> n1;
    vector<lli> v;

    if (n1 != 0) {
        for (lli i = 0; i <= n1; i++) {
            v.pb(1);
        }
    }

    for (lli i = 0; i < (n2 + 1) / 2; i++) {
        if (i == 0 && n1 != 0) {
            v.pb(0);
        } else {
            v.pb(10);
        }
    }

    lli flag = 0;

    if (n2 % 2 == 0 && n2 != 0) {
        flag = 1;
    }

    if (n2 == 0 && n3 != 0) {
        v.pb(0);
    }

    for (lli i = 0; i < n3; i++) {
        v.pb(0);
    }

    if (flag == 1) {
        v.pb(1);
    }

    for (lli i = 0; i < v.size(); i++) {
        cout << v[i];
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