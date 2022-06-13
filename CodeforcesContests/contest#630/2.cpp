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
    vector<lli> col(35, -1);
    vector<lli> ans(n + 2, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }
    lli val = 1;

    for (lli i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            if (col[2] == -1) {
                col[2] = val;
                val++;
            }
            ans[i] = col[2];
        } else if (v[i] % 3 == 0) {
            if (col[3] == -1) {
                col[3] = val;
                val++;
            }
            ans[i] = col[3];
        } else if (v[i] % 5 == 0) {
            if (col[5] == -1) {
                col[5] = val;
                val++;
            }
            ans[i] = col[5];
        } else if (v[i] % 7 == 0) {
            if (col[7] == -1) {
                col[7] = val;
                val++;
            }
            ans[i] = col[7];
        } else if (v[i] % 11 == 0) {
            if (col[11] == -1) {
                col[11] = val;
                val++;
            }
            ans[i] = col[11];
        } else if (v[i] % 13 == 0) {
            if (col[13] == -1) {
                col[13] = val;
                val++;
            }
            ans[i] = col[13];
        } else if (v[i] % 17 == 0) {
            if (col[17] == -1) {
                col[17] = val;
                val++;
            }
            ans[i] = col[17];
        } else if (v[i] % 19 == 0) {
            if (col[19] == -1) {
                col[19] = val;
                val++;
            }
            ans[i] = col[19];
        } else if (v[i] % 23 == 0) {
            if (col[23] == -1) {
                col[23] = val;
                val++;
            }
            ans[i] = col[23];
        } else if (v[i] % 29 == 0) {
            if (col[29] == -1) {
                col[29] = val;
                val++;
            }
            ans[i] = col[29];
        } else if (v[i] % 31 == 0) {
            if (col[31] == -1) {
                col[31] = val;
                val++;
            }
            ans[i] = col[31];
        }
    }

    lli mx = -1;

    for (lli i = 0; i < n; i++) {
        mx = max(mx, ans[i]);
    }
    cout << mx << endl;
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