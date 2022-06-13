#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
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
    lli n, u, r, l, d;
    cin >> n >> u >> r >> d >> l;

    for (lli i = 0; i < 32; i++) {
        lli tmp = i;
        vector<lli> v;
        while (sz(v) != 4) {
            v.pb(tmp % 2);
            tmp /= 2;
        }

        lli tmp_u = u, tmp_r = r, tmp_d = d, tmp_l = l;

        if (v[0] == 1) {
            tmp_u--;
            tmp_l--;
        }
        if (v[1] == 1) {
            tmp_u--;
            tmp_r--;
        }
        if (v[2] == 1) {
            tmp_r--;
            tmp_d--;
        }
        if (v[3] == 1) {
            tmp_l--;
            tmp_d--;
        }

        lli cnt = 0;
        if (tmp_u >= 0 && tmp_u <= n - 2) {
            cnt++;
        }
        if (tmp_r >= 0 && tmp_r <= n - 2) {
            cnt++;
        }
        if (tmp_d >= 0 && tmp_d <= n - 2) {
            cnt++;
        }
        if (tmp_l >= 0 && tmp_l <= n - 2) {
            cnt++;
        }

        if (cnt == 4) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}