#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
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
    lli n, a;
    cin >> n;
    vector<lli> v;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    lli no = 30;
    vector<lli> on(32, 0), zer(32, 0);
    vector<lli> vec(32, 0);
    lli p = 0, ans = 0;

    while (no > 0) {
        for (lli i = 0; i < n; i++) {
            if (v[i] % 2 == 0) {
                zer[p]++;
            } else {
                on[p]++;
            }
        }
        vec[p] += zer[p] * on[p];

        vec[p + 1] += (on[p] * (on[p] - 1)) / 2;

        if (vec[p] % 2 == 1) {
            ans += pow(2, p);
        }

        lli zz = 0, onn = 0;

        for (lli i = 0; i < n; i++) {
            if (v[i] % 2 == 1) {
                lli val = v[i] / 2;
                if (val % 2 == 0) {
                    zz++;
                } else {
                    onn++;
                }
            }
        }

        vec[p + 2] += zz * onn;

        for (lli i = 0; i < n; i++) {
            v[i] /= 2;
        }

        no--;
        p++;
    }

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