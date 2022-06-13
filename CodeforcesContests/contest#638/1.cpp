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
    lli n, a, ind;
    cin >> n;
    if (n == 2) {
        cout << "2" << endl;
        return;
    }

    vector<lli> v1, v2;
    for (lli i = 0; i < n / 2 - 1; i++) {
        v1.pb(i + 1);
        ind = i + 1;
    }
    v1.pb(n);
    lli beg = ind + 1;
    while (v2.size() != n / 2) {
        v2.pb(beg);
        beg++;
    }

    lli ans1 = 0, ans2 = 0;
    for (lli i = 0; i < v1.size(); i++) {
        ans1 += pow(2, v1[i]);
        ans2 += pow(2, v2[i]);
    }

    // cout << ans1 << ans2 << endl;
    cout << ans1 - ans2 << endl;
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