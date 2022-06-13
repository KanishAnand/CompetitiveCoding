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
    lli n1, n2, n3, a, sum = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    cin >> n1 >> n2 >> n3;
    vector<lli> v1, v2, v3;

    for (lli i = 0; i < n1; i++) {
        cin >> a;
        sum += a;
        sum1 += a;
        v1.pb(a);
    }
    for (lli i = 0; i < n2; i++) {
        cin >> a;
        sum += a;
        sum2 += a;
        v2.pb(a);
    }
    for (lli i = 0; i < n3; i++) {
        cin >> a;
        sum += a;
        sum3 += a;
        v3.pb(a);
    }

    sort(all(v1));
    sort(all(v2));
    sort(all(v3));

    lli mn = 1e18 + 5;
    if (sz(v1) == 1) {
        mn = min(mn, v1[0]);
    }
    if (sz(v2) == 1) {
        mn = min(mn, v2[0]);
    }
    if (sz(v3) == 1) {
        mn = min(mn, v3[0]);
    }

    vector<lli> tmp;
    tmp.pb(v1[0]);
    tmp.pb(v2[0]);
    tmp.pb(v3[0]);
    sort(all(tmp));
    mn = min(mn, tmp[0] + tmp[1]);

    mn = min({mn, sum1, sum2, sum3});

    lli ans = sum - 2 * mn;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}