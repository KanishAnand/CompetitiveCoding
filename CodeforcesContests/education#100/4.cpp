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
    vector<lli> mp(2 * n + 2, 0), v;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        mp[a] = 1;
    }

    vector<lli> mn(n + 2, 0);
    mn[0] = 1;

    lli beg = 1, end = n, lim = 0;

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli el = v[mid - 1], cnt = 0, flag = 1;

        for (lli i = 2 * n; i >= 1; i--) {
            if (mp[i] == 0) {
                cnt++;
                continue;
            }
            if (i <= el) {
                if (cnt == 0) {
                    flag = 0;
                    break;
                }
                cnt--;
            }
        }

        if (flag == 1) {
            beg = mid + 1;
            lim = mid;
        } else {
            end = mid - 1;
        }
    }

    for (lli i = 0; i <= lim; i++) {
        mn[i] = 1;
    }

    //second
    vector<lli> mx(n + 2, 0);
    mx[0] = 1;

    beg = 1, end = n, lim = 0;
    reverse(all(v));

    while (beg <= end) {
        lli mid = (beg + end) / 2;
        lli el = v[mid - 1], cnt = 0, flag = 1;

        for (lli i = 1; i <= 2 * n; i++) {
            if (mp[i] == 0) {
                cnt++;
                continue;
            }
            if (i >= el) {
                if (cnt == 0) {
                    flag = 0;
                    break;
                }
                cnt--;
            }
        }

        if (flag == 1) {
            beg = mid + 1;
            lim = mid;
        } else {
            end = mid - 1;
        }
    }

    for (lli i = 0; i <= lim; i++) {
        mx[i] = 1;
    }

    lli ans = 0;
    for (lli x = 0; x <= n; x++) {
        // cout << x << " " << mn[x] << " " << n - x << " " << mx[n - x] << endl;
        if (mn[x] == 1 && mx[n - x] == 1) {
            ans++;
        }
    }

    cout << ans << endl;
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