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

void fun(vector<lli> &no, vector<vector<vector<lli>>> &dp) {
    lli n = sz(no) - 1;

    dp[n][0][1] = 1;
    dp[n][1][1] = 9;
    dp[n][0][0] = 1;

    for (lli i = 1; i <= no[n]; i++) {
        dp[n][1][0]++;
    }

    for (lli ind = n - 1; ind >= 0; ind--) {
        for (lli req = 0; req <= 3; req++) {
            for (lli less = 0; less <= 1; less++) {
                lli higher;
                if (less == 1) {
                    higher = 9;
                } else {
                    higher = no[ind];
                }
                for (lli x = 0; x <= higher; x++) {
                    lli new_req = req;
                    if (x != 0) {
                        new_req--;
                    }
                    lli ch = (x < no[ind]);
                    lli new_less = (less | ch);
                    if (new_req >= 0) {
                        dp[ind][req][less] += dp[ind + 1][new_req][new_less];
                    }
                }
            }
        }
    }
}

void solve() {
    lli l, r;
    cin >> l >> r;

    lli tmp = l - 1;

    vector<lli> no;
    while (tmp > 0) {
        no.pb(tmp % 10);
        tmp /= 10;
    }

    reverse(all(no));

    vector<vector<vector<lli>>> dp1(20,
                                    vector<vector<lli>>(4, vector<lli>(2, 0)));

    if (l != 1) {
        fun(no, dp1);
    }
    lli ans1 = dp1[0][1][0] + dp1[0][2][0] + dp1[0][3][0];

    tmp = r;
    no.clear();
    while (tmp > 0) {
        no.pb(tmp % 10);
        tmp /= 10;
    }

    reverse(all(no));
    vector<vector<vector<lli>>> dp2(20,
                                    vector<vector<lli>>(4, vector<lli>(2, 0)));
    fun(no, dp2);
    lli ans2 = dp2[0][1][0] + dp2[0][2][0] + dp2[0][3][0];

    ans2 -= ans1;
    cout << ans2 << endl;
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