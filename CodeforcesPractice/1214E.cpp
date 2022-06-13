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
    vector<pair<lli, lli>> v;

    for (lli i = 0; i < n; i++) {
        cin >> a;
        v.pb({a, 2 * i + 1});
    }

    sort(v.rbegin(), v.rend());

    for (lli i = 0; i < sz(v) - 1; i++) {
        cout << v[i].second << " " << v[i + 1].second << endl;
    }

    for (lli i = 0; i < n; i++) {
        lli dis = v[i].first - 1, curr = v[i].second;
        lli node = v[i + dis].second;
        // cout << v[i].second << " " << node << " a" << dis << endl;
        if (i + dis + 1 == sz(v)) {
            v.pb({-1, curr + 1});
        }
        cout << node << " " << curr + 1 << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // lli t; cin >> t; while(t--)
    solve();
    rt;
}