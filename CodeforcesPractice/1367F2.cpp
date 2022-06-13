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
    lli n, a;
    cin >> n;
    vector<lli> v;
    map<lli, lli> mp, orig_cnt;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        orig_cnt[a]++;
    }

    vector<lli> tmp = v;
    sort(all(tmp));

    mp[tmp[0]] = -1;
    for (lli i = 1; i < tmp.size(); i++) {
        if (tmp[i] == tmp[i - 1]) {
            continue;
        }
        mp[tmp[i]] = tmp[i - 1];
    }

    vector<lli> dp(n + 2, 0);
    map<lli, lli> cnt;
    map<lli, lli> in;

    for (lli i = 0; i < n; i++) {
        lli val = mp[v[i]];
        // cout << val << endl;

        if (val != -1) {
            lli ind = in[val];
            if (ind != 0) {
                ind--;
                if (cnt[val] == orig_cnt[val]) {
                    dp[i] = max(dp[i], dp[ind] + 1);
                }
            } else {
                dp[i] = max(dp[i], 1ll);
            }
        }

        lli ind = in[v[i]];
        if (ind != 0) {
            ind--;
            dp[i] = max(dp[i], dp[ind] + 1);
        } else {
            dp[i] = max(dp[i], 1ll);
        }

        cnt[v[i]]++;
        in[v[i]] = i + 1;
    }

    lli ans = 0;
    for (lli i = 0; i < n; i++) {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    // cout << endl;

    cout << n - ans << endl;
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