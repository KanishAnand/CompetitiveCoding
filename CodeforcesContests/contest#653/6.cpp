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
const double PI = 3.14159265358979323846264338;
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
    lli n, a, k, b, t, m;
    cin >> n >>>> m >> k;
    vector<lli> v1, v2, v3;

    for (lli i = 0; i < n; i++) {
        cin >> t >> a >> b;
        if (a == 1 && b == 1) {
            v1.pb(t);
        } else if (a == 1 && b == 0) {
            v2.pb(t);
        } else if (a == 0 && b == 1) {
            v3.pb(t);
        }
    }

    sort(all(v1));
    sort(all(v2));
    sort(all(v3));

    lli ans = -1;

    vector<lli> pref(n + 2, 0);
    vector<lli> pref3(n + 2, 0), pref2(n + 2, 0);

    for (lli i = 0; i < v1.size(); i++) {
        pref[i + 1] = pref[i] + v1[i];
    }
    for (lli i = 0; i < v2.size(); i++) {
        pref2[i + 1] = pref2[i] + v2[i];
    }
    for (lli i = 0; i < v3.size(); i++) {
        pref3[i + 1] = pref3[i] + v3[i];
    }

    for (lli i = 0; i <= min(m, sz(v1)); i++) {
        lli val = pref[i];
        lli no = k - i;
        no = max(no, 0ll);

        if (v2.size() >= no && v3.size() >= no) {
            val += pref2[no];
            val += pref3[no];
            lli cnt = i + no + no;
            if (cnt <= m) {
                if (ans == -1) {
                    ans = val;
                } else {
                    ans = min(ans, val);
                }
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