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
    lli n, a, x;
    cin >> n >> x;
    vector<lli> v;
    lli ans = n, sum = 0;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
        sum += a;
    }

    if (sum % x != 0) {
        cout << n << endl;
        return;
    }

    lli val = 0, val2 = 0;

    for (lli i = 0; i < n; i++) {
        val += v[i];
        val2++;
        if (val % x != 0) {
            break;
        }
    }

    lli ans1 = n - val2;

    val = 0, val2 = 0;

    for (lli i = n - 1; i >= 0; i--) {
        val += v[i];
        val2++;
        if (val % x != 0) {
            break;
        }
    }

    lli ans2 = n - val2;
    ans = max(ans1, ans2);

    if (ans <= 0) {
        ans = -1;
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