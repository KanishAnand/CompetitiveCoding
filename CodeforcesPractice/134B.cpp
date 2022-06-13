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
    lli mn = 1e7;
    vector<lli> v;
    cin >> n;
    if (n == 1) {
        cout << "0" << endl;
        rt;
    }

    fr(i, 1, n) {
        lli steps = 1, oa, ob;
        a = i;
        b = n - i;
        while (a > 1 || b > 1) {
            oa = max(a, b);
            ob = min(a, b);
            a = oa - ob;
            b = ob;
            ++steps;
            if (a < 1 || b < 1) {
                break;
            }
        }
        if (a == 1 && b == 1) {
            mn = min(mn, steps);
        }
    }
    cout << mn << endl;
    rt;
}
