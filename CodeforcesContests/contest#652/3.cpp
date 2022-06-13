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
    vector<lli> v, v2;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb(a);
    }

    sort(all(v));
    lli ans = 0;
    lli beg = 0, end = n - 1;

    for (lli i = 0; i < k; i++) {
        cin >> a;
        if (a == 1) {
            ans += 2 * v[end];
            end--;
        } else {
            v2.pb(a);
        }
    }

    if (v2.size() == 0) {
        cout << ans << endl;
        return;
    }

    sort(all(v2));

    for (lli j = sz(v2) - 1; j >= 0; j--) {
        ans += (v[beg] + v[end]);
        beg++;
        end--;
        v2[j] -= 2;
        beg += v2[j];
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