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
// for multiset
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     new_data_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

void solve() {
    lli n, a;
    cin >> n;
    string st;
    cin >> st;

    vector<lli> LR_pref(n + 3, 0), RL_pref(n + 3, 0);
    for (lli i = 1; i <= n; i++) {
        if (st[i - 1] == 'L') {
            LR_pref[i] = RL_pref[i - 1] + 1;
        } else {
            RL_pref[i] = LR_pref[i - 1] + 1;
        }
    }

    vector<lli> LR_suff(n + 3, 0), RL_suff(n + 3, 0);
    for (lli i = n - 1; i >= 0; i--) {
        if (st[i] == 'R') {
            RL_suff[i] = LR_suff[i + 1] + 1;
        } else {
            LR_suff[i] = RL_suff[i + 1] + 1;
        }
    }

    for (lli i = 0; i <= n; i++) {
        lli len = 1;
        len += LR_pref[i];
        len += RL_suff[i];
        cout << len << " ";
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