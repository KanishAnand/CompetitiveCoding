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

set<pair<lli, lli>> v;

void fun(lli start, lli k) {
    for (lli i = start + 1; i <= k; i++) {
        v.insert({start, i});
    }
    for (lli i = start + 1; i <= k; i++) {
        v.insert({i, k + 1});
        v.insert({i, k + 2});
    }
    v.insert({k + 1, k + 2});

    for (lli i = start + 1; i <= k; i++) {
        for (lli j = i + 1; j <= k; j++) {
            v.insert({i, j});
        }
    }

    for (lli i = start + 1; i <= k; i += 2) {
        auto it = v.find({i, i + 1});
        v.erase(it);
    }
}

void solve() {
    lli k;
    cin >> k;
    if (k % 2 == 0) {
        cout << "NO" << endln;
        return;
    }

    if (k == 1) {
        cout << "YES" << endln;
        cout << "2 1" << endln;
        cout << "1 2" << endln;
        return;
    }

    fun(1, k);
    v.insert({1, k + 3});
    fun(k + 3, 2 * k + 2);

    cout << "YES" << endln;
    cout << 2 * k + 4 << " " << sz(v) << endl;
    for (auto val : v) {
        cout << val.first << " " << val.second << endln;
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