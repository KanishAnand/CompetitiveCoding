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
    lli n, t, w;
    cin >> n;

    lli a, b;
    multiset<lli> st1;
    multiset<pair<lli, lli>> st2;

    for (lli i = 0; i < n; i++) {
        cin >> t >> w;
        if (i == 0) {
            a = t;
            b = w;
        } else if (t > a) {
            st1.insert(w - t + 1);
        } else {
            st2.insert({t, w});
        }
    }

    lli ans = st1.size() + 1;

    while (st1.size() != 0) {
        auto it = st1.begin();
        lli val = *it;
        if (a >= val) {
            a -= val;
            st1.erase(it);
            while (st2.size() != 0) {
                auto itt = st2.end();
                itt--;
                lli c = itt->first;
                lli d = itt->second;
                if (c > a) {
                    st1.insert(d - c + 1);
                    st2.erase(itt);
                } else {
                    break;
                }
            }
            ans = min(ans, sz(st1) + 1);
        } else {
            break;
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