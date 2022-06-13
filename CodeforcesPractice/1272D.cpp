#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// // for multiset
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
// //              tree_order_statistics_node_update>
// //     new_data_set;
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
    lli n, a;
    vector<lli> v;
    cin >> n;
    input(n, v);
    vector<lli> dpl(n + 4, 0), dpr(n + 4, 0);
    lli ans = -1;
    dpl[1] = 1;
    for (lli i = 2; i < n; i++) {
        if (v[i - 1] > v[i - 2]) {
            dpl[i] = dpl[i - 1] + 1;
        } else {
            dpl[i] = 1;
        }
        ans = max(ans, dpl[i]);
    }

    if (v[n - 1] > v[n - 2]) {
        ans = max(ans, dpl[n - 1] + 1);
    }

    dpr[n - 2] = 1;
    for (lli i = n - 3; i >= 0; i--) {
        if (v[i + 1] < v[i + 2]) {
            dpr[i] = dpr[i + 1] + 1;
        } else {
            dpr[i] = 1;
        }
    }

    ans = max(ans, dpr[0]);
    ans = max(ans, dpl[n - 1]);
    for (lli i = 1; i < n - 1; i++) {
        if (v[i - 1] < v[i + 1]) {
            ans = max(ans, dpl[i] + dpr[i]);
        }
    }

    cout << ans << endl;
    rt;
}
