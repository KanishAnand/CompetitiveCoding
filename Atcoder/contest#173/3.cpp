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
    lli h, w, k;
    cin >> h >> w >> k;
    vector<string> store;
    string st;

    for (lli i = 0; i < h; i++) {
        cin >> st;
        store.pb(st);
    }

    lli ans = 0;
    lli a = pow(2, h);
    lli b = pow(2, w);

    for (lli i = 0; i < a; i++) {
        lli no = i, cnt = 0;
        vector<lli> rows;
        while (no > 0) {
            lli rem = no % 2;
            if (rem == 1) {
                rows.pb(cnt);
            }
            no /= 2;
            cnt++;
        }
        for (lli j = 0; j < b; j++) {
            vector<string> tmp = store;
            lli no = j, cnt = 0;
            vector<lli> cols;
            while (no > 0) {
                lli rem = no % 2;
                if (rem == 1) {
                    cols.pb(cnt);
                }
                no /= 2;
                cnt++;
            }

            for (auto val1 : rows) {
                for (int p = 0; p < w; p++) {
                    tmp[val1][p] = '.';
                }
            }
            for (lli p = 0; p < h; p++) {
                for (auto val2 : cols) {
                    tmp[p][val2] = '.';
                }
            }

            lli check = 0;
            for (lli ii = 0; ii < h; ii++) {
                for (lli jj = 0; jj < w; jj++) {
                    if (tmp[ii][jj] == '#') {
                        check++;
                    }
                }
            }
            if (check == k) {
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