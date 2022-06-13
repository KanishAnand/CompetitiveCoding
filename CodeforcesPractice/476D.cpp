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
    v = {1, 3, 4, 5};
    lli odd = 7;

    for (lli i = 1; i < n; i++) {
        v.pb(odd);
        v.pb(odd + 2);
        v.pb(odd + 3);
        v.pb(odd + 4);
        odd += 6;
    }

    cout << (odd - 2) * k << endl;
    lli ind = 0;
    for (lli i = 0; i < n; i++) {
        cout << k * v[ind] << " " << k * v[ind + 1] << " " << k * v[ind + 2] << " " << k * v[ind + 3] << endl;
        ind += 4;
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