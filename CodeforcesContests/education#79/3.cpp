#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
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
    lli n, a, t, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<lli> ind;
        new_data_set v;
        ind.resize(n + 2, 0);
        fr(i, 0, n) {
            cin >> a;
            ind[a] = i + 1;
        }
        lli ans = 0, val = -1;
        fr(i, 0, m) {
            cin >> a;
            v.insert(ind[a]);
            if (i == 0) {
                ans += 2 * (ind[a] - 1) + 1;
                if (ind[a] > val) {
                    val = ind[a];
                }
            } else {
                if (ind[a] > val) {
                    val = ind[a];
                    lli cnt = v.order_of_key(ind[a]);
                    ans += 2 * (ind[a] - 1 - cnt) + 1;
                } else {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    rt;
}
