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
    lli n, a;
    cin >> n;
    vector<lli> v;
    vector<lli> mp(2e5 + 2, 0);
    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        if (mp[a] == 1) {
            v.pb(a);
        }
    }

    sort(all(v));

    vector<lli> dp(2e5 + 2, 0);
    dp[v[0]] = mp[v[0]];

    lli ans = mp[v[0]], close = v[0];

    for (lli i = 1; i < sz(v); i++) {
        lli val = v[i];
        if (mp[val] == 1) {
            lli no = dp[val - 1] + 1;
            if (no > ans) {
                ans = no;
                close = val;
            }
            dp[val] = mp[val];
        } else {
            dp[val] = dp[val - 1] + mp[val];
            if (dp[val] > ans) {
                ans = dp[val];
                close = val;
            }
        }
    }

    cout << ans << endl;
    while (mp[close] > 0) {
        cout << close << " ";
        mp[close]--;
    }
    close--;

    lli flag = 0;
    vector<lli> store;

    while (flag == 0) {
        if (mp[close] == 0) {
            break;
        }
        if (mp[close] == 1) {
            flag = 1;
        }
        store.pb(close);
        close--;
    }

    for (lli i = 0; i < store.size(); i++) {
        cout << store[i] << " ";
        mp[store[i]]--;
    }

    for (lli i = sz(store) - 1; i >= 0; i--) {
        while (mp[store[i]] > 0) {
            cout << store[i] << " ";
            mp[store[i]]--;
        }
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