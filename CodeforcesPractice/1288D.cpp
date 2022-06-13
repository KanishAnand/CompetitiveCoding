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
    lli n, a, m;
    cin >> n >> m;
    vector<vector<lli>> arr(n + 2);
    lli beg = 0, end = -1;

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < m; j++) {
            cin >> a;
            end = max(end, a);
            arr[i].pb(a);
        }
    }

    lli ansi, ansj, ans = -1, indi, indj;
    while (beg <= end) {
        lli mid = (beg + end) / 2;
        vector<lli> mask(1 << m, -1);

        for (lli i = 0; i < n; i++) {
            lli p = 1, msk = 0;
            for (lli j = 0; j < m; j++) {
                if (arr[i][j] >= mid) {
                    msk += p;
                }
                p *= 2;
            }
            mask[msk] = i + 1;
        }

        lli val = (1 << m) - 1, flag = 0;

        for (lli i = 0; i <= val; i++) {
            for (lli j = 0; j <= val; j++) {
                if (mask[i] != -1 && mask[j] != -1 && (i | j) >= val) {
                    indi = mask[i];
                    indj = mask[j];
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }

        if (flag == 0) {
            end = mid - 1;
        } else {
            beg = mid + 1;
            if (mid > ans) {
                ans = mid;
                ansi = indi;
                ansj = indj;
            }
        }
    }

    // cout << ans << endl;
    cout << ansi << "  " << ansj << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}