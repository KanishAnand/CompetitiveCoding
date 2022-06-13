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
    lli n, m, a;
    cin >> m >> n;

    vector<lli> resp;
    for (lli i = 0; i < n; i++) {
        cout << "1" << endl;
        cin >> a;
        if (a == 0) {
            return;
        }
        if (a == 1) {
            resp.pb(1);
        } else {
            resp.pb(0);
        }
    }

    lli beg = 1, end = m, cnt = 0;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        cout << mid << endl;
        cin >> a;
        if (resp[cnt % n] == 0) {
            a = -a;
        }
        if (a == 0) {
            return;
        }
        if (a == 1) {
            beg = mid + 1;
        } else {
            end = mid - 1;
        }
        cnt++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}