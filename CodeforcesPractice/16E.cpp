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
    lli n;
    cin >> n;
    double a;
    vector<vector<double>> prob(n + 2);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            cin >> a;
            prob[i].pb(a);
        }
    }

    vector<double> dp(pow(2, n), 0);
    dp[0] = 1;

    for (lli mask = 1; mask < pow(2, n); mask++) {
        lli tmp = mask, ind = 0;
        vector<lli> dead, live;
        while (tmp > 0) {
            if (tmp % 2) {
                dead.pb(ind);
            } else {
                live.pb(ind);
            }
            ind++;
            tmp /= 2;
        }

        while (ind < n) {
            live.pb(ind);
            ind++;
        }

        for (auto dd : dead) {
            lli tmp_no = pow(2, dd);
            lli new_mask = (mask ^ tmp_no);
            for (auto lv : live) {
                dp[mask] += (prob[lv][dd] * dp[new_mask]);
            }
        }
    }

    cout << fixed << setprecision(8);
    double sum = 0;
    lli all_one = pow(2, n) - 1;
    vector<double> masks;

    for (lli i = 0; i < n; i++) {
        lli tmp = pow(2, i);
        lli mask = (all_one ^ tmp);
        sum += dp[mask];
        masks.pb(dp[mask]);
    }

    for (auto val : masks) {
        double no = val / sum;
        cout << no << " ";
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}