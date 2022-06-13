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
    string st;
    cin >> st;
    n = st.length();

    lli cnt = 0, mn = 0;
    map<lli, lli> mp;

    for (lli i = 0; i < n; i++) {
        if (st[i] == '+') {
            cnt++;
        } else {
            cnt--;
        }
        mn = min(mn, cnt);
        if (cnt < 0) {
            if (mp[cnt] == 0) {
                mp[cnt] = i + 1;
            }
        }
    }

    lli ans = 0;
    for (lli i = 0; i < abs(mn); i++) {
        lli val = -i - 1;
        lli ind = mp[val];
        ans += ind;
    }

    ans += n;
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