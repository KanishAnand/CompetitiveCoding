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
    lli n, a, m;
    vector<lli> v1, v2;
    cin >> n >> m;
    input(n, v1);
    input(n, v2);
    sort(all(v1));
    sort(all(v2));
    lli val = v1[0], ans = 1e10;
    fr(i, 0, n) {
        lli p;
        if (v2[i] < val) {
            p = m - val + v2[i];
        } else {
            p = v2[i] - val;
        }
        lli flag = 0;
        fr(j, 0, n) {
            if ((v1[j] + p) % m != v2[(j + i) % n]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            ans = min(ans, p);
        }
    }
    cout << ans << endl;
    rt;
}