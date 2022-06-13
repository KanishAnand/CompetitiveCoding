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
    lli n;
    string st;
    cin >> n;
    cin >> st;
    vector<lli> va(n + 2, 0), vc(n + 2, 0), vg(n + 2, 0), vt(n + 2, 0);

    for (lli i = 0; i < n; i++) {
        if (i != 0) {
            va[i] = va[i - 1];
            vc[i] = vc[i - 1];
            vg[i] = vg[i - 1];
            vt[i] = vt[i - 1];
        }

        if (st[i] == 'A') {
            va[i]++;
        } else if (st[i] == 'C') {
            vc[i]++;
        } else if (st[i] == 'G') {
            vg[i]++;
        } else {
            vt[i]++;
        }
    }

    lli ans = 0, a, c, g, t;

    for (lli i = 0; i < n; i++) {
        for (lli j = i + 1; j < n; j++) {
            a = va[j] - va[i];
            c = vc[j] - vc[i];
            g = vg[j] - vg[i];
            t = vt[j] - vt[i];
            if (st[i] == 'A') {
                a++;
            } else if (st[i] == 'C') {
                c++;
            } else if (st[i] == 'G') {
                g++;
            } else {
                t++;
            }
            if (a == t && g == c) {
                ans++;
            }
        }
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