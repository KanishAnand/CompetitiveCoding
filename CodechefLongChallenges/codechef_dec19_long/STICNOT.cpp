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
    lli n, a, b, c, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<lli> v, ve;
        lli a, b, c;
        fr(i, 0, n - 1) {
            cin >> a >> b >> c;
            v.pb(c);
        }
        sort(all(v));
        v.pb(v[v.size() - 1]);
        fr(i, 0, n) {
            cin >> a;
            ve.pb(a);
        }
        sort(all(ve));

        lli beg = 0, end = n;
        while (beg <= end) {
            lli mid = (beg + end) / 2;
            lli flag = 0, cnt = 0;
            for (lli i = mid; i < n; i++) {
                if (ve[i] < v[cnt]) {
                    flag = 1;
                    break;
                }
                ++cnt;
            }
            if (flag == 1) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        cout << beg << endl;
    }
    rt;
}
