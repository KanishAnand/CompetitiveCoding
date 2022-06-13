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
    lli n, a, p;
    cin >> n >> p;
    vector<lli> v;
    lli mx = -1;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mx = max(mx, a);
        v.pb(a);
    }

    sort(all(v));

    lli beg = 1, end = mx;
    lli mn = 1e10, start = 1e10;

    while (beg <= end) {
        lli x = (beg + end) / 2;
        lli no = x;
        lli flag1 = 1, flag2 = 1;
        for (lli i = 0; i < n; i++) {
            auto it = upper_bound(v.begin(), v.end(), no);
            lli calc = it - v.begin();
            lli ch = calc - i;
            if (ch <= 0) {
                flag1 = 0;
                break;
            }
            if (ch % p == 0) {
                flag2 = 0;
                break;
            }
            no++;
        }

        if (flag1 == 0) {
            beg = x + 1;
            start = max(start, x + 1);
        } else {
            if (flag2 == 0) {
                mn = min(mn, x - 1);
                end = x - 1;
            } else {
                beg = x + 1;
            }
        }
    }

    lli ans = mn - start + 1;
    for (lli i = start; i <= mn; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}