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
    vector<lli> v;
    while (a > 0) {
        v.pb(a % 10);
        a /= 10;
    }

    sort(all(v));

    lli p = 1;
    lli no1 = 0, no2 = 0;
    for (lli i = 0; i < sz(v); i++) {
        no1 += p * v[i];
        p *= 10;
    }

    p = 1;
    for (lli i = sz(v) - 1; i >= 0; i--) {
        no2 += p * v[i];
        p *= 10;
    }

    lli ans = no1 - no2;
    return ans;
}

void solve() {
    lli n, k;
    cin >> n >> k;
    for (lli i = 0; i < k; i++) {
        n = fun(n);
    }

    cout << n << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}