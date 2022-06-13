#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
// gcd function
// __gcd(a, b)
// for max of n elements
// cout<<max({a,b,c,d})<<endl;

lli input(lli n, vector<lli> &ve);
lli input(lli n, vector<lli> &ve) {
    lli val;
    for (lli i = 0; i < n; i++) {
        cin >> val;
        ve.pb(val);
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli n, a, p, q, r;
    vector<lli> v;
    cin >> n >> p >> q >> r;
    vector<lli> val1(n + 1, 0), val2(n + 1, 0), val3(n + 1, 0);
    input(n, v);
    val1[0] = p * v[0];

    for (lli i = 1; i < n; i++) {
        val1[i] = max(val1[i - 1], p * v[i]);
    }

    val2[0] = q * v[0] + val1[0];

    for (lli i = 1; i < n; i++) {
        val2[i] = max(val2[i - 1], val1[i] + q * v[i]);
    }

    val3[0] = r * v[0] + val2[0];

    for (lli i = 1; i < n; i++) {
        val3[i] = max(val3[i - 1], val2[i] + r * v[i]);
    }

    lli ans = val3[0];
    fr(i, 1, n) {
        ans = max(val3[i], ans);
    }
    cout << ans << endl;
    rt;
}
