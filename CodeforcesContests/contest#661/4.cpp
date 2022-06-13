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
    lli n, a;
    string st;
    cin >> n;
    cin >> st;

    lli cnt = 1;
    vector<lli> ans(n + 2, 0);

    set<lli> one, zero;

    for (lli i = 0; i < n; i++) {
        if (st[i] == '1') {
            if (zero.size() == 0) {
                one.insert(cnt);
                ans[i] = cnt;
                cnt++;
            } else {
                auto it = zero.begin();
                lli val = *it;
                ans[i] = val;
                zero.erase(it);
                one.insert(val);
            }
        } else {
            if (one.size() == 0) {
                zero.insert(cnt);
                ans[i] = cnt;
                cnt++;
            } else {
                auto it = one.begin();
                lli val = *it;
                ans[i] = val;
                one.erase(it);
                zero.insert(val);
            }
        }
    }

    cout << cnt - 1 << endl;
    for (lli i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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