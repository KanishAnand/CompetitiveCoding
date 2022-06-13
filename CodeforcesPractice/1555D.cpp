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
#define len(x) (lli)(x.length())
const lli MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
// cout << fixed << setprecision(0) << pi <<endl;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// for multiset use pair instead of int
// order_of_key(val): returns the number of values strictly less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, m;
    cin >> n >> m;
    string st;
    cin >> st;

    vector<string> possible = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<lli>> pref(n + 2, vector<lli>(6, 0));

    for (lli ind = 0; ind < sz(possible); ind++) {
        for (lli i = 0; i < n; i++) {
            if (i != 0) {
                pref[i][ind] = pref[i - 1][ind];
            }

            if (st[i] != possible[ind][i % 3]) {
                pref[i][ind]++;
            }
        }
    }

    lli l, r;
    while (m--) {
        cin >> l >> r;
        lli ans = 1e7;
        for (lli ind = 0; ind < sz(possible); ind++) {
            lli val = pref[r - 1][ind];
            if (l > 1) {
                val -= pref[l - 2][ind];
            }
            ans = min(ans, val);
        }

        cout << ans << endl;
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