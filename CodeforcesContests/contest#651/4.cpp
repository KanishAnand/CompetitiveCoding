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

    lli even = k / 2, odd = k / 2;
    if (k % 2 == 1) {
        odd++;
    }

    vector<lli> v;
    set<lli> st;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        st.insert(a);
        v.pb(a);
    }

    vector<lli> nos;
    for (auto it : st) {
        nos.pb(it);
    }

    lli beg = 0, end = sz(nos) - 1;
    lli ans = 1e10;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli val = nos[mid];

        // even place
        lli pp;
        if (k % 2 == 1) {
            pp = n - 2;
        } else {
            pp = n - 1;
        }

        vector<vector<lli>> dp(n + 2, vector<lli>(2, 0));
        if (v[1] <= val) {
            dp[1][1]++;
        }

        for (lli i = 2; i <= pp; i++) {
            if (v[i] <= val) {
                dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 2][1] + 1);
                dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
            }
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }

        lli cnt = 0;
        for (lli i = 0; i < n; i++) {
            cnt = max(cnt, dp[i][0]);
            cnt = max(cnt, dp[i][1]);
        }

        if (cnt >= even) {
            ans = min(ans, val);
            end = mid - 1;
            continue;
        }

        // odd place
        vector<vector<lli>> dp2(n + 2, vector<lli>(2, 0));

        lli qq;
        if (k % 2 == 1) {
            qq = n - 1;
        } else {
            qq = n - 2;
        }

        if (v[0] <= val) {
            dp2[0][1]++;
        }
        if (v[1] <= val) {
            dp2[1][1]++;
        }

        dp2[1][0] = dp2[0][1];

        for (lli i = 2; i <= qq; i++) {
            if (v[i] <= val) {
                dp2[i][1] = max(dp2[i - 1][0] + 1, dp2[i - 2][1] + 1);
                dp2[i][1] = max(dp2[i][1], dp2[i - 2][0] + 1);
            }
            dp2[i][0] = max(dp2[i - 1][1], dp2[i - 1][0]);
        }

        cnt = 0;
        for (lli i = 0; i < n; i++) {
            cnt = max(cnt, dp2[i][0]);
            cnt = max(cnt, dp2[i][1]);
        }

        if (cnt >= odd) {
            ans = min(ans, val);
            end = mid - 1;
            continue;
        } else {
            beg = mid + 1;
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