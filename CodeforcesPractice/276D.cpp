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
#define sz(x) (lli)(x.size())
// cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;

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
    lli n, a, b;
    vector<lli> va, vb, ans;
    cin >> a >> b;
    lli mx;
    while (a > 0) {
        va.pb(a % 2);
        a /= 2;
    }
    while (b > 0) {
        vb.pb(b % 2);
        b /= 2;
    }
    mx = max(sz(va), sz(vb));

    while (sz(va) < mx) {
        va.pb(0);
    }
    while (sz(vb) < mx) {
        vb.pb(0);
    }

    reverse(all(va));
    reverse(all(vb));
    lli flag = 0;
    fr(i, 0, mx) {
        if (va[i] != vb[i]) {
            flag = 1;
            break;
        }
        ans.pb(0);
    }
    if (flag == 1) {
        while (sz(ans) < mx) {
            ans.pb(1);
        }
    }

    reverse(all(ans));
    lli p = 1, val = 0;
    fr(i, 0, mx) {
        val += ans[i] * p;
        p *= 2;
    }
    cout << val << endl;
    rt;
}
