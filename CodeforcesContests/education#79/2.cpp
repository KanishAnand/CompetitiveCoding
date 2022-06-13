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
// cout << fixed << setprecision(0) << pi <<endl;

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
    lli n, a, t;
    cin >> t;
    while (t--) {
        lli s;
        cin >> n >> s;
        vector<lli> v;
        vector<lli> ve;
        lli sum = 0;
        fr(i, 0, n) {
            cin >> a;
            sum += a;
            ve.pb(a);
            v.pb(sum);
        }
        if (sum <= s) {
            cout << "0" << endl;
            continue;
        }

        lli ans = -1, ind = 0;
        fr(i, 0, n) {
            lli p = ve[i];
            auto it = lower_bound(v.begin(), v.end(), s + p);
            auto it1 = lower_bound(v.begin(), v.end(), s);
            if (it == v.end()) {
                --it;
            }
            if (it1 == v.end()) {
                --it1;
            }
            if (*it > s + p) {
                // if (it == v.begin()) {
                //     continue;
                // }
                --it;
            }

            lli val = it - v.begin();
            if (val > ans && val >= i) {
                ans = val - 1;
                ind = i + 1;
            }
            if (*it1 > s) {
                // if (it1 == v.begin()) {
                //     continue;
                // }
                --it1;
            }
            lli val1 = it1 - v.begin();
            if (val1 > ans) {
                ans = val1;
                ind = i + 1;
            }
        }
        cout << ind << endl;
    }
    rt;
}
