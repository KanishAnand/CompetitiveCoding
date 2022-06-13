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
    lli n, a, k;
    cin >> n >> k;
    string st;
    cin >> st;
    lli p = n / k, ans = 0;

    for (lli i = 0; i < k / 2; i++) {
        vector<lli> cnt(30, 0);
        lli mx = -1, ind = -1;

        for (lli j = 0; j < p; j++) {
            lli val1 = st[i + j * k] - 'a';
            lli q = (j + 1) * k - i - 1;
            lli val2 = st[q] - 'a';
            // cout << q << endl;
            // cout << val1 << " " << val2 << endl;

            cnt[val1]++;
            cnt[val2]++;

            if (cnt[val1] > mx) {
                mx = cnt[val1];
                ind = val1;
            }

            if (cnt[val2] > mx) {
                mx = cnt[val2];
                ind = val2;
            }
        }

        ans += 2 * p - cnt[ind];
    }

    // cout << ans << endl;

    if (k % 2 == 1) {
        lli i = k / 2, mx = -1, ind;
        vector<lli> cnt(30, 0);

        for (lli j = 0; j < p; j++) {
            lli val1 = st[i + j * k] - 'a';
            cnt[val1]++;
            if (cnt[val1] > mx) {
                mx = cnt[val1];
                ind = val1;
            }
        }

        ans += p - cnt[ind];
    }

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--) {
        solve();
    }
    rt;
}