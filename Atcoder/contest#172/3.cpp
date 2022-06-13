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
const double PI = 3.14159265358979323846264338;
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
    lli n, a, m, k;
    cin >> n >> m >> k;
    vector<lli> v1, v2;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v1.pb(a);
    }

    for (lli i = 1; i < n; i++) {
        v1[i] += v1[i - 1];
    }

    for (lli i = 0; i < m; i++) {
        cin >> a;
        v2.pb(a);
    }

    lli ans = 0, no = k;
    auto it = lower_bound(v1.begin(), v1.end(), no);
    lli ind = 0;
    if (it != v1.end() && *it == no) {
        ind = it - v1.begin();
        ind++;
    } else if (it != v1.begin()) {
        it--;
        ind = it - v1.begin();
        ind++;
    }

    ans = ind;

    lli val = 0;
    for (lli i = 0; i < m; i++) {
        val += v2[i];
        if (val > k) {
            break;
        }
        lli no = k - val;
        lli p = i + 1;
        auto it = lower_bound(v1.begin(), v1.end(), no);
        lli ind = 0;
        if (it != v1.end() && *it == no) {
            ind = it - v1.begin();
            ind++;
        } else if (it != v1.begin()) {
            it--;
            ind = it - v1.begin();
            ind++;
        }
        p += ind;
        ans = max(ans, p);
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