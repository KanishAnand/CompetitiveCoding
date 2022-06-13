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
    vector<lli> v;

    set<lli> st_min, st_max;
    for (lli i = 0; i < n; i++) {
        cin >> a;
        st_min.insert(i + 1);
        v.pb(a);
    }

    vector<lli> ans_min(n, -1), ans_max(n, -1);

    for (lli i = 0; i < n; i++) {
        if (i == 0) {
            st_min.erase(v[i]);
            ans_min[i] = v[i];
            ans_max[i] = v[i];
            continue;
        }
        if (v[i] != v[i - 1]) {
            st_min.erase(v[i]);
            ans_min[i] = v[i];
            ans_max[i] = v[i];
        }
    }

    st_max = st_min;

    for (lli i = 0; i < n; i++) {
        if (ans_min[i] != -1) {
            continue;
        }
        auto it = st_min.begin();
        ans_min[i] = *it;
        st_min.erase(it);
    }

    for (lli i = 0; i < n; i++) {
        if (ans_max[i] != -1) {
            continue;
        }
        auto it = st_max.upper_bound(v[i]);
        it--;
        ans_max[i] = *it;
        st_max.erase(it);
    }

    for (lli i = 0; i < n; i++) {
        cout << ans_min[i] << " ";
    }
    cout << endl;
    for (lli i = 0; i < n; i++) {
        cout << ans_max[i] << " ";
    }
    cout << endl;
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