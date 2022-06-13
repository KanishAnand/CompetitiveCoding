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
    lli n, a, b, c, zero = 0;
    cin >> n;
    vector<lli> v;
    map<lli, lli> mp;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        mp[a]++;
        if (a == 0) {
            zero++;
        }
        v.pb(a);
    }

    lli ans = max(2ll, zero);

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            lli len = 2;
            a = v[i];
            b = v[j];
            if (a == 0 && b == 0) {
                continue;
            }
            mp[a]--;
            mp[b]--;
            while (1) {
                c = a + b;
                if (mp[c] <= 0) {
                    break;
                }
                len++;
                mp[c]--;
                a = b;
                b = c;
            }
            ans = max(ans, len);

            a = v[i];
            b = v[j];
            mp[a]++;
            mp[b]++;
            len -= 2;
            while (len) {
                c = a + b;
                mp[c]++;
                a = b;
                b = c;
                len--;
            }
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