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
    lli n, a, q;
    cin >> q;
    while (q--) {
        vector<lli> v;
        cin >> n;
        lli on = n;
        while (on > 0) {
            v.pb(on % 3);
            on /= 3;
        }

        lli ind = -1, ind0 = -1;
        for (lli i = v.size() - 1; i >= 0; i--) {
            if (v[i] == 2) {
                ind = i;
                break;
            } else if (v[i] == 0) {
                ind0 = i;
            }
        }

        lli flag = 0;
        if (ind != -1) {
            if (ind0 != -1) {
                v[ind0] = 1;
            } else {
                flag = 1;
            }
        }
        if (ind == -1) {
            cout << n << endl;
            continue;
        }

        lli p = 1, ans = 0;
        for (lli i = 0; i < v.size(); i++) {
            if (i >= ind0) {
                ans += p * v[i];
            }
            p *= 3;
        }

        if (flag == 1) {
            ans = p;
        }
        cout << ans << endl;
    }
    rt;
}
