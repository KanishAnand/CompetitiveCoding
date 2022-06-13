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
    int n, p;
    cin >> n;
    vector<int> v;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> p;
        mx = max(mx, p);
        v.pb(p);
    }

    lli ans = 0;

    vector<vector<int>> pref(n + 2, vector<int>(mx + 2, 0));
    vector<vector<int>> suff(n + 2, vector<int>(mx + 2, 0));

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            pref[i] = pref[i - 1];
        }
        pref[i][v[i]]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            suff[i] = suff[i + 1];
        }
        suff[i][v[i]]++;
    }

    lli a, b;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            a = pref[i - 1][v[j]];
            b = suff[j + 1][v[i]];
            ans += (a * b);
        }
    }

    cout << ans << endln;
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